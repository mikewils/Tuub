////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// zmoelnig@iem.kug.ac.at 
//
// Implementation file
//
//    Copyright (c) 2000 Guenter Geiger geiger@epy.co.at
//    Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::für::umläute. IEM
//    Copyright (c) 2002 James Tittle & Chris Clepper
//    For information on usage and redistribution, and for a DISCLAIMER OF ALL
//    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
//
/////////////////////////////////////////////////////////

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
}

/////////////////////////////////////////////////////////
// signal Performance
t_int* pix_scanned :: perform(t_int* w)
{
  pix_scanned *x = GetMyClass((void*)w[1]);
  // hey this is RGBA only !!!
  t_float* out_red =   (t_float*)(w[2]);
  t_float* out_green = (t_float*)(w[3]);
  t_float* out_blue =  (t_float*)(w[4]);
  t_float* out_alpha = (t_float*)(w[5]);
  int N = (t_int)(w[6]);
  t_float phs = 0.f;
  int xcor = 0;
  int ycor = 0;
  

  unsigned char* data = x->m_data;
  long int pix_size   = x->m_size;
  int n = (N<pix_size)?N:pix_size;


  ::post("chRed: %d", chRed);
  ::post("chGreen: %d", chGreen);
  ::post("chBlue: %d", chBlue);
  ::post("chAlpha: %d", chAlpha);
  ::post("pix_size: %d", pix_size);
  ::post("csize: %d", x->m_csize);
  ::post("xsize: %d", x->m_xsize);

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
	xcor = sinelu(phs, 30);
	ycor = coslu(phs, 50);
	//	data[ (xcor + ycor * xsize) * csize ];
	

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
