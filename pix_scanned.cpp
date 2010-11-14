#include <math.h>
#include "sinetable.h"
#define HELPSYMBOL "pix_sig2pix~"

#include "pix_scanned.h"

CPPEXTERN_NEW(pix_scanned)

/////////////////////////////////////////////////////////
//
// pix_scanned
//
/////////////////////////////////////////////////////////
// Constructor
//
/////////////////////////////////////////////////////////
pix_scanned :: pix_scanned() : m_data(NULL), m_size(0)
{
  int i=4;
  while(i--)
    o_col[i]=outlet_new(this->x_obj, &s_signal);
  floatinlet_new(this->x_obj, &this->m_scanspeed);
  floatinlet_new(this->x_obj, &this->m_xradius);
  floatinlet_new(this->x_obj, &this->m_yradius);
  this->m_phs = 0.f;
  this->m_x1 = 0.f;
  this->m_y1 = 0.f;
  this->m_xradius = 10.f;
  this->m_yradius = 10.f;
  this->m_scanspeed= 0.001;
}

/////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
pix_scanned :: ~pix_scanned()
{
  int i=4;
  while(i--)outlet_free(o_col[i]);
  m_data = NULL;
  m_size = 0;
}

/////////////////////////////////////////////////////////
// static member function
//
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
// processImage
/////////////////////////////////////////////////////////
void pix_scanned :: processImage(imageStruct &image)
{
  m_data = image.data;
  m_size = image.xsize * image.ysize;
  m_csize = image.csize;
  m_format = image.format;
  m_xsize = image.xsize;
  m_ysize = image.ysize;
}

/////////////////////////////////////////////////////////
// Signal Performance
t_int* pix_scanned :: perform(t_int* w)
{
  pix_scanned *x = GetMyClass((void*)w[1]);
  // hey this is RGBA only !!!
  t_float* out_red =   (t_float*)(w[2]);
  t_float* out_green = (t_float*)(w[3]);
  t_float* out_blue =  (t_float*)(w[4]);
  t_float* out_alpha = (t_float*)(w[5]);
  int N = (t_int)(w[6]);
  t_float phs = x->m_phs;
  int xcor = 0;
  int ycor = 0;
  int xsize = x->m_xsize;
  int ysize = x->m_ysize;
  t_float x1 = x->m_x1;
  t_float y1 = x->m_y1;
  t_float scanspeed = x->m_scanspeed;
  t_float xradius = x->m_xradius;
  t_float yradius = x->m_yradius;

  unsigned char* data = x->m_data;
  long int pix_size   = x->m_size;
  int n = N;

  //  ::post("xradius: %f", xradius);
  //::post("yradius: %f", yradius);

#if 0
  ::post("chRed: %d", chRed);
  ::post("chGreen: %d", chGreen);
  ::post("chBlue: %d", chBlue);
  ::post("chAlpha: %d", chAlpha);
  ::post("pix_size: %d", pix_size);
  ::post("csize: %d", x->m_csize);
  ::post("xsize: %d", x->m_xsize);
#endif 
 
  if (x->m_data){
    t_float scale0, scale1, scale2, scale3;
    scale0 = scale1 = scale2 = scale3 = 1./255.;
    int csize=x->m_csize;
    switch (csize){
    default:
      scale3=1./255.;
    case 3:
      scale2=1./255.;
    case 2:
      scale1=1./255.;
    case 1:
      scale0=1./255.;
    case 0:
      break;
    }
    switch(x->m_format){
    case GL_RGBA: default:
      while(n--){
	float x;
	int idx;
	xcor = sinelu(phs, xradius) + ((int)(xsize/2));
	ycor = coslu(phs, yradius) + ((int)ysize/2);
	idx = (xcor + ycor * xsize) * csize;

        idx = (idx >= pix_size ? pix_size -1 : idx);
        idx = (idx < 0 ? 0 : idx);

	x = (((float) 
	      (data[  idx ] + 
	       data[ idx + 1] + 
	       data[ idx + 2])) / (255.0 * 3));


	y1 = x - x1 + 0.994 * y1;
	x1 = x;

	*(out_red++) = y1;

	phs += scanspeed;
	//phs += 0.027;

	
#if 0
	if ((n % 64) == 0) {
	  //	  ::post("%f", ((float) (data[(xcor + ycor * xsize) * csize + 0])) / 255.0);
	  ::post("%f", scanspeed);
	}
#endif
	

#if 0
	*(out_red  ++) = data[chRed]  *scale0;
	*(out_green++) = data[chGreen]*scale1;
	*(out_blue ++) = data[chBlue] *scale2;
	*(out_alpha++) = data[chAlpha]*scale3;
	data+=csize;
#endif

      }
      break;

    case GL_YUV422_GEM:
      n/=2;
      while(n--){
	*(out_red  ++) = data[chY0]   *scale0;
	*(out_red  ++) = data[chY1]   *scale0;
	*(out_green++) = data[chU] *scale1;
	*(out_green++) = data[chU] *scale1;
	*(out_blue ++) = data[chV] *scale2;
	*(out_blue ++) = data[chV] *scale2;
	*(out_alpha++) = 0; *(out_alpha++) = 0;
	data+=4;
      }
      break;
    case GL_LUMINANCE:

      ::post("its luminance");
      
      while(n--){
	*(out_red  ++) = data[chGray]*scale0;
	*(out_green++) = 0;
	*(out_blue ++) = 0;
	*(out_alpha++) = 0;
	data++;
      }
      break;
    }
  } else {
    n=N;
    while (n--) *out_red++=*out_green++=*out_blue++=*out_alpha++=0;
  }

  x->m_x1 = x1;
  x->m_y1 = y1;

  x->m_phs = phs;
  return (w+7);
}

void pix_scanned :: dspMess(void *data, t_signal** sp)
{
  dsp_add(perform, 6, data, sp[0]->s_vec, sp[1]->s_vec, sp[2]->s_vec, sp[3]->s_vec, sp[0]->s_n);
}

/////////////////////////////////////////////////////////
// Callback functions
//
/////////////////////////////////////////////////////////

void pix_scanned :: obj_setupCallback(t_class *classPtr)
{
  class_addcreator((t_newmethod)create_pix_scanned, gensym("pix_scanned~"), A_NULL);
  class_addmethod(classPtr, (t_method)pix_scanned::dspMessCallback, 
		  gensym("dsp"), A_NULL);
}

void pix_scanned :: dspMessCallback(void *data,t_signal** sp)
{
  GetMyClass(data)->dspMess(data, sp);
}
