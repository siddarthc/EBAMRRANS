#include "REAL.H"
#include "SPACE.H"
#include "CONSTANTS.H"

#include "CONSTANTS.H"
      subroutine DIVERGESTENF(
     &           idcalclo0,idcalclo1
     &           ,idcalchi0,idcalchi1
     &           ,divf
     &           ,idivflo0,idivflo1
     &           ,idivfhi0,idivfhi1
     &           ,ndivfcomp
     &           ,flux
     &           ,ifluxlo0,ifluxlo1
     &           ,ifluxhi0,ifluxhi1
     &           ,nfluxcomp
     &           ,facedir
     &           ,nconserved
     &           ,dx
     &           )

      implicit none
      integer CHF_ID(0:5,0:5)
      data CHF_ID/ 1,0,0,0,0,0 ,0,1,0,0,0,0 ,0,0,1,0,0,0 ,0,0,0,1,0,0 ,0,0,0,0,1,0 ,0,0,0,0,0,1 /


      integer idcalclo0,idcalclo1
      integer idcalchi0,idcalchi1
      integer ndivfcomp
      integer idivflo0,idivflo1
      integer idivfhi0,idivfhi1
      REAL_T divf(
     &           idivflo0:idivfhi0,
     &           idivflo1:idivfhi1,
     &           0:ndivfcomp-1)
      integer nfluxcomp
      integer ifluxlo0,ifluxlo1
      integer ifluxhi0,ifluxhi1
      REAL_T flux(
     &           ifluxlo0:ifluxhi0,
     &           ifluxlo1:ifluxhi1,
     &           0:nfluxcomp-1)
      integer facedir
      integer nconserved
      REAL_T dx
      integer i, j
      integer ioff, joff
      integer spacedim,iv
      
      ioff = chf_id(0,facedir)
      joff = chf_id(1,facedir)
      spacedim = CH_SPACEDIM
      do iv = 0,nconserved - 1
         
      do j = idcalclo1,idcalchi1
      do i = idcalclo0,idcalchi0

         divf(i,j,iv) = divf(i,j,iv) +
     &        (flux(i+ioff,j+joff,iv)
     &        -flux(i     ,j     ,iv))/dx
         
      enddo
      enddo
      enddo
      return
      end
