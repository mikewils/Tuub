/*-----------------------------------------------------------------
  LOG
  GEM - Graphics Environment for Multimedia

  Output a pixel-buffer as 4 signals

  Copyright (c) 2002 IOhannes m zmölnig <zmoelnig@iem.kug.ac.at>
  Copyright (c) Günther Geiger. geiger@epy.co.at
  Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::für::umläute. IEM. zmoelnig@iem.kug.ac.at
  Copyright (c) 2002 James Tittle & Chris Clepper
  For information on usage and redistribution, and for a DISCLAIMER OF ALL
  WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

  -----------------------------------------------------------------*/

#ifndef INCLUDE_PIX_SCANNED_H_
#define INCLUDE_PIX_SCANNED_H_

#include <string.h>
#include "Base/GemPixObj.h"

/*-----------------------------------------------------------------
  -------------------------------------------------------------------
  CLASS
  pix_scanned
    
  Interprete a pixel-image as 4 RGBA-signals
    
  KEYWORDS
  pix
    
  DESCRIPTION

  4 outlets with signals : R~, G~, B~, A~
    
  -----------------------------------------------------------------*/
class GEM_EXTERN pix_scanned : public GemPixObj
{
  CPPEXTERN_HEADER(pix_scanned, GemPixObj)

    public:

  //////////
  // Constructor
  pix_scanned();
    	
 protected:


  //////////
  // Destructor
  virtual      ~pix_scanned();

  //////////
  // DSP perform
  static t_int* perform(t_int* w);

  //////////
  // processImage
  virtual void  processImage(imageStruct &image);

  //////////
  // DSP-Message
  virtual void  dspMess(void *data, t_signal** sp);

  //-----------------------------------
  // GROUP:	Image data
  //-----------------------------------
    
  //////////
  // The pixBlock with the current image
  //  pixBlock    	m_pixBlock;
  unsigned char *m_data;
  long int       m_size;
  int            m_csize;
  int            m_xsize;
  int            m_ysize;
  int            m_format;
  t_float m_phs;
  t_float m_x1;
  t_float m_y1;
  t_float m_yradius;
  t_float m_xradius;
  t_float m_scanspeed;
  int m_counter;
  //////////
  // the outlets~
  t_outlet *o_col[4];

  float sigbuf[4096*4];
  float last_scanline[4096*4];
  //  float last_scanline2[4096*4];

 private:
    	
  //////////
  // static member functions
  static void   dspMessCallback(void* data,t_signal** sp);
};

#endif	// for header file
