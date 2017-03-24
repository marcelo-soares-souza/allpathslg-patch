///////////////////////////////////////////////////////////////////////////////
//                   SOFTWARE COPYRIGHT NOTICE AGREEMENT                     //
//       This software and its documentation are copyright (2010) by the     //
//   Broad Institute.  All rights are reserved.  This software is supplied   //
//   without any warranty or guaranteed support whatsoever. The Broad        //
//   Institute is not responsible for its use, misuse, or functionality.     //
///////////////////////////////////////////////////////////////////////////////

#ifndef SCOREALIGNMENTONE
#define SCOREALIGNMENTONE

#include "PackAlign.h"
#include "Alignment.h"
#include "math/Arith.h"
#include "Basevector.h"
#include "Qualvector.h"

Float ScoreAlignment( const allpathslg::align & a, const basevector& rd1,
                      const qualvector& scores1, const basevector& rd2,
                      const qualvector& scores2 = qualvector(0), int start1 = 0,
                      int stop1 = -1, int start2 = 0, int stop2 = -1, Bool ignore_gaps = False );

Float ScoreAlignment( Bool rd2_is_rc, const allpathslg::align & a, const basevector& rd1,
                      const qualvector& scores1, const basevector& rd2,
                      const qualvector& scores2 = qualvector(0), int start1 = 0,
                      int stop1 = -1, int start2 = 0, int stop2 = -1, Bool ignore_gaps = False );

int ScoreAlignmentPoly( const allpathslg::align & a, const basevector& rd1,
                        const qualvector& scores1, const basevector& rd2,
                        const qualvector& scores2 = qualvector(0), int start1 = 0,
                        int stop1 = -1, int start2 = 0, int stop2 = -1 );

int ScoreAlignmentPoly( Bool rd2_is_rc, const allpathslg::align & a, const basevector& rd1,
                        const qualvector& scores1, const basevector& rd2,
                        const qualvector& scores2 = qualvector(0), int start1 = 0,
                        int stop1 = -1, int start2 = 0, int stop2 = -1 );

void Regap( allpathslg::align & a,
            const basevector& rd1, const qualvector& scores1,
            const basevector& rd2, const qualvector& scores2 );

void Regap( Bool rd2_is_rc, allpathslg::align & a,
            const basevector& rd1, const qualvector& scores1,
            const basevector& rd2, const qualvector& scores2 );

inline
void Regap( alignment& a,
            const basevector& rd1, const qualvector& scores1,
            const basevector& rd2, const qualvector& scores2 )
{
  allpathslg::align al = allpathslg::align (a);
  Regap( al, rd1, scores1, rd2, scores2 );
  // Debugando - Gambiarra a.Set( packalign(al), a.Errors( ) );
}

#endif
