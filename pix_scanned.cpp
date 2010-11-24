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
  int i=1;
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
  this->m_counter = 0;
}

/////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
pix_scanned :: ~pix_scanned()
{
  int i=1;
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
  int k;
  int xcor;
  int ycor;
  int idx;
  float x;
  float phs = 0.f;
  int xradius = m_xradius;
  int yradius = m_yradius;

  m_data = image.data;
  m_size = image.xsize * image.ysize;
  m_csize = image.csize;
  m_format = image.format;
  m_xsize = image.xsize;
  m_ysize = image.ysize;
  unsigned char *data = m_data;
  float scanspeed = m_scanspeed;
  int numsamps = (int) (1.0/scanspeed);


#if 1
  for (k=0; k<numsamps; k++) {
    xcor = sinelu(phs, xradius) + ((int)(m_xsize/2));
    ycor = coslu(phs, yradius) + ((int)(m_ysize/2));
    idx = (xcor + ycor * m_xsize) * m_csize;
    
    idx = (idx >=  m_size * m_csize ? (m_size -1) * m_size : idx);
    idx = (idx < 0 ? 0 : idx);
    
    x = (((float) 
	  (((int) data[  idx ] / 12) + 
	   ((int) (data[ idx + 1] )) + 
	   ((int) (data[ idx + 2] / 12)))) / (255.0 * 3));

    data[idx] = 0;
    data[idx+1] = 0;
    data[idx+2] = 0;
    
    phs += scanspeed;
   
    // Subtract the last scanline from the current scanline, dump to
    // audio buffer
    //       y1 = x - x1 + 0.992 * y1;
    //      x1 = x;

    float tmp = x + (last_scanline[k & (4*4096-1)] * 0.72);
    // Store current scanline for the next pass
    sigbuf[k & (4*4096-1)] = tmp-last_scanline[k & (4*4096-1)];
    last_scanline[k&(4*4096-1)] = tmp;
  }
#endif
    
}

/////////////////////////////////////////////////////////
// Signal Performance
t_int* pix_scanned :: perform(t_int* w)
{
  pix_scanned *x = GetMyClass((void*)w[1]);
  // hey this is RGBA only !!!
  t_float* out_red =   (t_float*)(w[2]);
  //  t_float* out_green = (t_float*)(w[3]);
  //t_float* out_blue =  (t_float*)(w[4]);
  //t_float* out_alpha = (t_float*)(w[5]);
  int N = (t_int)(w[3]);
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
  t_float *sigbuf = x->sigbuf;
  int counter = x->m_counter;

  unsigned char* data = x->m_data;
  long int pix_size   = x->m_size;
  int n = N;
  int numsamps = (int) (1.f/scanspeed);

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
    while(n--){
      float x;
      int idx;

      
      x = sigbuf[(counter % numsamps) & (4*4096-1)];
      counter ++;
      
      y1 = x - x1 + 0.992 * y1;
      x1 = x;
      
      *(out_red++) = y1;
      
      //      phs += scanspeed;
      //phs += 0.027;
      
      
#if 0
      if ((n % 64) == 0) {
	//	  ::post("%f", ((float) (data[(xcor + ycor * xsize) * csize + 0])) / 255.0);
	::post("%f", scanspeed);
      }
#endif
    }
  } else {
    n=N;
    while (n--) *out_red++=0;
  }

  x->m_x1 = x1;
  x->m_y1 = y1;
  x->m_phs = phs;
  x->m_counter = counter;

  return (w+4);
}


void pix_scanned :: dspMess(void *data, t_signal** sp)
{
  dsp_add(perform, 3, data, sp[0]->s_vec, sp[0]->s_n);
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
