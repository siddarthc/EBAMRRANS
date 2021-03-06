#include "REAL.H"
#include "SPACE.H"
#include "CONSTANTS.H"

#include "CONSTANTS.H"
      subroutine EBAMRPDOTPROD(
     &           sum
     &           ,aone
     &           ,iaonelo0,iaonelo1
     &           ,iaonehi0,iaonehi1
     &           ,atwo
     &           ,iatwolo0,iatwolo1
     &           ,iatwohi0,iatwohi1
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      REAL_T sum
      integer iaonelo0,iaonelo1
      integer iaonehi0,iaonehi1
      REAL_T aone(
     &           iaonelo0:iaonehi0,
     &           iaonelo1:iaonehi1)
      integer iatwolo0,iatwolo1
      integer iatwohi0,iatwohi1
      REAL_T atwo(
     &           iatwolo0:iatwohi0,
     &           iatwolo1:iatwohi1)
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer i,j
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

      sum = sum + aone(i,j)*atwo(i,j)
      
      enddo
      enddo
      return
      end
      subroutine GETINVDIAGRHS(
     &           lhs
     &           ,ilhslo0,ilhslo1
     &           ,ilhshi0,ilhshi1
     &           ,nlhscomp
     &           ,rhs
     &           ,irhslo0,irhslo1
     &           ,irhshi0,irhshi1
     &           ,nrhscomp
     &           ,scale
     &           ,ncomp
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      integer nlhscomp
      integer ilhslo0,ilhslo1
      integer ilhshi0,ilhshi1
      REAL_T lhs(
     &           ilhslo0:ilhshi0,
     &           ilhslo1:ilhshi1,
     &           0:nlhscomp-1)
      integer nrhscomp
      integer irhslo0,irhslo1
      integer irhshi0,irhshi1
      REAL_T rhs(
     &           irhslo0:irhshi0,
     &           irhslo1:irhshi1,
     &           0:nrhscomp-1)
      REAL_T scale
      integer ncomp
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer i,j, ivar
      do ivar = 0, ncomp-1
         
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

         lhs(i,j, ivar) = scale*rhs(i,j, ivar)
         
      enddo
      enddo
      enddo
      return
      end
      subroutine MAXNORM(
     &           max
     &           ,vel
     &           ,ivello0,ivello1
     &           ,ivelhi0,ivelhi1
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      REAL_T max
      integer ivello0,ivello1
      integer ivelhi0,ivelhi1
      REAL_T vel(
     &           ivello0:ivelhi0,
     &           ivello1:ivelhi1)
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer i,j
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

      if(abs(vel(i,j)).gt.max) max=abs(vel(i,j))
      
      enddo
      enddo
      return
      end
      subroutine MAXNORMMASK(
     &           max
     &           ,vel
     &           ,ivello0,ivello1
     &           ,ivelhi0,ivelhi1
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           ,mask
     &           ,imasklo0,imasklo1
     &           ,imaskhi0,imaskhi1
     &           )

      implicit none
      REAL_T max
      integer ivello0,ivello1
      integer ivelhi0,ivelhi1
      REAL_T vel(
     &           ivello0:ivelhi0,
     &           ivello1:ivelhi1)
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer imasklo0,imasklo1
      integer imaskhi0,imaskhi1
      integer mask(
     &           imasklo0:imaskhi0,
     &           imasklo1:imaskhi1)
      integer i,j
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

      if(mask(i,j).ge.zero) then
         if(abs(vel(i,j)).gt.max) max=abs(vel(i,j))
      endif
      
      enddo
      enddo
      return
      end
      subroutine MAXNORMHYBRID(
     &           max
     &           ,vel
     &           ,ivello0,ivello1
     &           ,ivelhi0,ivelhi1
     &           ,tau
     &           ,itaulo0,itaulo1
     &           ,itauhi0,itauhi1
     &           ,asquared
     &           ,density
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      REAL_T max
      integer ivello0,ivello1
      integer ivelhi0,ivelhi1
      REAL_T vel(
     &           ivello0:ivelhi0,
     &           ivello1:ivelhi1)
      integer itaulo0,itaulo1
      integer itauhi0,itauhi1
      REAL_T tau(
     &           itaulo0:itauhi0,
     &           itaulo1:itauhi1)
      REAL_T asquared
      REAL_T density
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer i,j
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

      if((abs(vel(i,j))+sqrt((tau(i,j)+asquared)/density)).gt.max)
     &     max=abs(vel(i,j))+sqrt((tau(i,j)+asquared)/density)
      
      enddo
      enddo
      return
      end
      subroutine MAXNORMMASKHYBRID(
     &           max
     &           ,vel
     &           ,ivello0,ivello1
     &           ,ivelhi0,ivelhi1
     &           ,tau
     &           ,itaulo0,itaulo1
     &           ,itauhi0,itauhi1
     &           ,asquared
     &           ,density
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           ,mask
     &           ,imasklo0,imasklo1
     &           ,imaskhi0,imaskhi1
     &           )

      implicit none
      REAL_T max
      integer ivello0,ivello1
      integer ivelhi0,ivelhi1
      REAL_T vel(
     &           ivello0:ivelhi0,
     &           ivello1:ivelhi1)
      integer itaulo0,itaulo1
      integer itauhi0,itauhi1
      REAL_T tau(
     &           itaulo0:itauhi0,
     &           itaulo1:itauhi1)
      REAL_T asquared
      REAL_T density
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer imasklo0,imasklo1
      integer imaskhi0,imaskhi1
      integer mask(
     &           imasklo0:imaskhi0,
     &           imasklo1:imaskhi1)
      integer i,j
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

      if(mask(i,j).ge.zero) then
         if((abs(vel(i,j))+sqrt((tau(i,j)+asquared)/density)).gt.max)
     &        max=abs(vel(i,j))+sqrt((tau(i,j)+asquared)/density)
      endif
      
      enddo
      enddo
      return
      end
      subroutine MINNORM(
     &           min
     &           ,vel
     &           ,ivello0,ivello1
     &           ,ivelhi0,ivelhi1
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      REAL_T min
      integer ivello0,ivello1
      integer ivelhi0,ivelhi1
      REAL_T vel(
     &           ivello0:ivelhi0,
     &           ivello1:ivelhi1)
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer i,j
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

      if(abs(vel(i,j)).lt.min) min=abs(vel(i,j))
      
      enddo
      enddo
      return
      end
      subroutine MINNORMMASK(
     &           min
     &           ,vel
     &           ,ivello0,ivello1
     &           ,ivelhi0,ivelhi1
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           ,mask
     &           ,imasklo0,imasklo1
     &           ,imaskhi0,imaskhi1
     &           )

      implicit none
      REAL_T min
      integer ivello0,ivello1
      integer ivelhi0,ivelhi1
      REAL_T vel(
     &           ivello0:ivelhi0,
     &           ivello1:ivelhi1)
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer imasklo0,imasklo1
      integer imaskhi0,imaskhi1
      integer mask(
     &           imasklo0:imaskhi0,
     &           imasklo1:imaskhi1)
      integer i,j
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

      if(mask(i,j).ge.zero) then
         if(abs(vel(i,j)).lt.min) min=abs(vel(i,j))
      endif
      
      enddo
      enddo
      return
      end
      subroutine AMRPZEROSUB(
     &           phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,nphicomp
     &           ,ioverlayboxlo0,ioverlayboxlo1
     &           ,ioverlayboxhi0,ioverlayboxhi1
     &           ,ncomp
     &           )

      implicit none
      integer nphicomp
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1,
     &           0:nphicomp-1)
      integer ioverlayboxlo0,ioverlayboxlo1
      integer ioverlayboxhi0,ioverlayboxhi1
      integer ncomp
      integer i,j
      integer ivar
      do ivar = 0, ncomp-1
         
      do j = ioverlayBoxlo1,ioverlayBoxhi1
      do i = ioverlayBoxlo0,ioverlayBoxhi0

         phi(i,j, ivar) = zero
         
      enddo
      enddo
      enddo
      return
      end
      subroutine DOALLREGULARMULTICOLOR(
     &           phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,rhs
     &           ,irhslo0,irhslo1
     &           ,irhshi0,irhshi1
     &           ,weight
     &           ,alpha
     &           ,beta
     &           ,dx
     &           ,icoloredboxlo0,icoloredboxlo1
     &           ,icoloredboxhi0,icoloredboxhi1
     &           )

      implicit none
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1)
      integer irhslo0,irhslo1
      integer irhshi0,irhshi1
      REAL_T rhs(
     &           irhslo0:irhshi0,
     &           irhslo1:irhshi1)
      REAL_T weight
      REAL_T alpha
      REAL_T beta
      REAL_T dx(0:1)
      integer icoloredboxlo0,icoloredboxlo1
      integer icoloredboxhi0,icoloredboxhi1
      integer i,j
      real_t laplphi, dx0,dx1
      dx0 = beta/(dx(0) * dx(0))
                dx1 = beta/(dx(1) * dx(1))
      
      do j = icoloredBoxlo1,icoloredBoxhi1,2
      do i = icoloredBoxlo0,icoloredBoxhi0,2

        laplphi = 
     &     (    phi(i+1,j  )
     &     +    phi(i-1,j  )
     $     -two*phi(i  ,j  ))*dx0 
     $     +(   phi(i  ,j+1)
     &     +    phi(i  ,j-1)
     $     -two*phi(i  ,j  ))*dx1 
        laplphi = laplphi + alpha * phi(i,j)
        phi(i,j) = phi(i,j) +
     &     weight*(rhs(i,j) - laplphi)
      
      enddo
      enddo
      return
      end
      subroutine DOALLREGULARUPDATE(
     &           phinew
     &           ,iphinewlo0,iphinewlo1
     &           ,iphinewhi0,iphinewhi1
     &           ,phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,rhs
     &           ,irhslo0,irhslo1
     &           ,irhshi0,irhshi1
     &           ,weight
     &           ,alpha
     &           ,beta
     &           ,dx
     &           ,icoloredboxlo0,icoloredboxlo1
     &           ,icoloredboxhi0,icoloredboxhi1
     &           )

      implicit none
      integer iphinewlo0,iphinewlo1
      integer iphinewhi0,iphinewhi1
      REAL_T phinew(
     &           iphinewlo0:iphinewhi0,
     &           iphinewlo1:iphinewhi1)
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1)
      integer irhslo0,irhslo1
      integer irhshi0,irhshi1
      REAL_T rhs(
     &           irhslo0:irhshi0,
     &           irhslo1:irhshi1)
      REAL_T weight
      REAL_T alpha
      REAL_T beta
      REAL_T dx(0:1)
      integer icoloredboxlo0,icoloredboxlo1
      integer icoloredboxhi0,icoloredboxhi1
      integer i,j
      real_t laplphi, dx0,dx1
      dx0 = beta/(dx(0) * dx(0))
                dx1 = beta/(dx(1) * dx(1))
      
      do j = icoloredBoxlo1,icoloredBoxhi1,2
      do i = icoloredBoxlo0,icoloredBoxhi0,2

        laplphi = 
     &     (    phi(i+1,j  )
     &     +    phi(i-1,j  )
     $     -two*phi(i  ,j  ))*dx0 
     $     +(   phi(i  ,j+1)
     &     +    phi(i  ,j-1)
     $     -two*phi(i  ,j  ))*dx1 
        laplphi = laplphi + alpha * phi(i,j)
        phinew(i,j) = phi(i,j) +
     &     weight*(rhs(i,j) - laplphi)
      
      enddo
      enddo
      return
      end
      subroutine DOALLREGULARGSRB(
     &           phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,rhs
     &           ,irhslo0,irhslo1
     &           ,irhshi0,irhshi1
     &           ,weight
     &           ,alpha
     &           ,beta
     &           ,dx
     &           ,iregionlo0,iregionlo1
     &           ,iregionhi0,iregionhi1
     &           ,redBlack
     &           )

      implicit none
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1)
      integer irhslo0,irhslo1
      integer irhshi0,irhshi1
      REAL_T rhs(
     &           irhslo0:irhshi0,
     &           irhslo1:irhshi1)
      REAL_T weight
      REAL_T alpha
      REAL_T beta
      REAL_T dx(0:1)
      integer iregionlo0,iregionlo1
      integer iregionhi0,iregionhi1
      integer redBlack
      integer i,j
      integer imin,imax,indtot
      real_t laplphi, dx0,dx1
      dx0 = beta/(dx(0) * dx(0))
                dx1 = beta/(dx(1) * dx(1))
#if CH_SPACEDIM==3
      do k=iregionlo2, iregionhi2
#endif
#if CH_SPACEDIM > 1
         do j=iregionlo1, iregionhi1
#endif
            imin = iregionlo0
            indtot = imin + j 
            imin = imin + abs(mod(indtot + redBlack, 2))
            imax = iregionhi0
            do i = imin, imax, 2
               laplphi = 
     &              (    phi(i+1,j  )
     &              +    phi(i-1,j  )
     $              -two*phi(i  ,j  ))*dx0 
     $              +(   phi(i  ,j+1)
     &              +    phi(i  ,j-1)
     $              -two*phi(i  ,j  ))*dx1 
               laplphi = laplphi + alpha * phi(i,j)
               phi(i,j) = phi(i,j) +
     &              weight*(rhs(i,j) - laplphi)
            enddo
#if CH_SPACEDIM > 1
         enddo
#endif
#if CH_SPACEDIM==3
      enddo
#endif
      return
      end
      subroutine SLOWGSRBEBAMRPO(
     &           phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,lph
     &           ,ilphlo0,ilphlo1
     &           ,ilphhi0,ilphhi1
     &           ,rhs
     &           ,irhslo0,irhslo1
     &           ,irhshi0,irhshi1
     &           ,lam
     &           ,ilamlo0,ilamlo1
     &           ,ilamhi0,ilamhi1
     &           ,icoloredboxlo0,icoloredboxlo1
     &           ,icoloredboxhi0,icoloredboxhi1
     &           )

      implicit none
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1)
      integer ilphlo0,ilphlo1
      integer ilphhi0,ilphhi1
      REAL_T lph(
     &           ilphlo0:ilphhi0,
     &           ilphlo1:ilphhi1)
      integer irhslo0,irhslo1
      integer irhshi0,irhshi1
      REAL_T rhs(
     &           irhslo0:irhshi0,
     &           irhslo1:irhshi1)
      integer ilamlo0,ilamlo1
      integer ilamhi0,ilamhi1
      REAL_T lam(
     &           ilamlo0:ilamhi0,
     &           ilamlo1:ilamhi1)
      integer icoloredboxlo0,icoloredboxlo1
      integer icoloredboxhi0,icoloredboxhi1
      integer i,j
      REAL_T phio, lamo, rhso, lpho
      
      do j = icoloredboxlo1,icoloredboxhi1,2
      do i = icoloredboxlo0,icoloredboxhi0,2

         phio  = phi(i,j)
         lamo  = lam(i,j)
         rhso  = rhs(i,j)
         lpho  = lph(i,j)
         phi(i,j) =
     $        phi(i,j) +
     $        lam(i,j)*(
     $        rhs(i,j) -
     $        lph(i,j))
       
      enddo
      enddo
      return
      end
      subroutine DOALLREGULARJACOBI(
     &           phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,rhs
     &           ,irhslo0,irhslo1
     &           ,irhshi0,irhshi1
     &           ,weight
     &           ,alpha
     &           ,beta
     &           ,dx
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1)
      integer irhslo0,irhslo1
      integer irhshi0,irhshi1
      REAL_T rhs(
     &           irhslo0:irhshi0,
     &           irhslo1:irhshi1)
      REAL_T weight
      REAL_T alpha
      REAL_T beta
      REAL_T dx(0:1)
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer i,j
      real_t laplphi, dx0,dx1
      dx0 = beta/(dx(0) * dx(0))
                dx1 = beta/(dx(1) * dx(1))
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

        laplphi = 
     &     (    phi(i+1,j  )
     &     +    phi(i-1,j  )
     $     -two*phi(i  ,j  ))*dx0 
     $     +(   phi(i  ,j+1)
     &     +    phi(i  ,j-1)
     $     -two*phi(i  ,j  ))*dx1 
        laplphi = laplphi + alpha * phi(i,j)
        phi(i,j) = phi(i,j) +
     &     weight*(rhs(i,j) - laplphi)
      
      enddo
      enddo
      return
      end
      subroutine UNDOREGULARGS(
     &           phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,rhs
     &           ,irhslo0,irhslo1
     &           ,irhshi0,irhshi1
     &           ,weight
     &           ,alpha
     &           ,beta
     &           ,dx
     &           ,iv
     &           )

      implicit none
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1)
      integer irhslo0,irhslo1
      integer irhshi0,irhshi1
      REAL_T rhs(
     &           irhslo0:irhshi0,
     &           irhslo1:irhshi1)
      REAL_T weight
      REAL_T alpha
      REAL_T beta
      REAL_T dx(0:1)
      integer iv(0:1)
      integer i,j
      real_t sublaplphi, dx0,dx1
      real_t bigk, sumtwooverh2, numer
      
      i = iv(0)
      j = iv(1)
      
      dx0 = one/(dx(0) * dx(0))
      dx1 = one/(dx(1) * dx(1))
      sumtwooverh2 = two*dx0 + two*dx1
      bigk = one + weight*alpha - beta*weight*sumtwooverh2
      sublaplphi = 
     &     (    phi(i+1,j  )
     &     +    phi(i-1,j  ))*dx0 
     $     +(   phi(i  ,j+1)
     &     +    phi(i  ,j-1))*dx1 
      numer = phi(i,j)
     $     + weight*rhs(i,j) - weight*beta*sublaplphi
      phi(i,j) = numer/bigk
      return
      end
        subroutine REGAPPLYDOMAINFLUX_INPLACE(
     &           phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,faceflux
     &           ,ifacefluxlo0,ifacefluxlo1
     &           ,ifacefluxhi0,ifacefluxhi1
     &           ,dx
     &           ,side
     &           ,idir
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      integer CHF_ID(0:5,0:5)
      data CHF_ID/ 1,0,0,0,0,0 ,0,1,0,0,0,0 ,0,0,1,0,0,0 ,0,0,0,1,0,0 ,0,0,0,0,1,0 ,0,0,0,0,0,1 /


      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1)
      integer ifacefluxlo0,ifacefluxlo1
      integer ifacefluxhi0,ifacefluxhi1
      REAL_T faceflux(
     &           ifacefluxlo0:ifacefluxhi0,
     &           ifacefluxlo1:ifacefluxhi1)
      REAL_T dx
      integer side
      integer idir
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
        integer i,j, ioff,joff
        ioff = chf_id(0,idir)
                  joff = chf_id(1,idir)
        
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

        if (side.eq.1) then
          phi(i,j) =
     &         phi(     i-ioff,j-joff) +
     &         faceflux(i-ioff,j-joff)*dx
        else
          phi(i,j) =
     &         phi(     i+ioff,j+joff) -
     &         faceflux(i+ioff,j+joff)*dx
        endif
        
      enddo
      enddo
        return
        end
      subroutine REGGET1DLAPLACIAN_INPLACE(
     &           opphidir
     &           ,iopphidirlo0,iopphidirlo1
     &           ,iopphidirhi0,iopphidirhi1
     &           ,phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,beta
     &           ,dx
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           )

      implicit none
      integer iopphidirlo0,iopphidirlo1
      integer iopphidirhi0,iopphidirhi1
      REAL_T opphidir(
     &           iopphidirlo0:iopphidirhi0,
     &           iopphidirlo1:iopphidirhi1)
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1)
      REAL_T beta
      REAL_T dx(0:1)
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer i,j
      real_t laplphi, dx0,dx1
      dx0 = beta/(dx(0) * dx(0))
                dx1 = beta/(dx(1) * dx(1))
      
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0

      laplphi = 
     &     (    phi(i+1,j  )
     &     +    phi(i-1,j  )
     $     -two*phi(i  ,j  ))*dx0 
     $     +(   phi(i  ,j+1)
     &     +    phi(i  ,j-1)
     $     -two*phi(i  ,j  ))*dx1 
      opphidir(i,j) = opphidir(i,j) + laplphi
      
      enddo
      enddo
      return
      end
      subroutine REGGET1DLAPLACIAN(
     &           opphidir
     &           ,iopphidirlo0,iopphidirlo1
     &           ,iopphidirhi0,iopphidirhi1
     &           ,phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,dx
     &           ,beta
     &           ,idir
     &           ,iloboxlo0,iloboxlo1
     &           ,iloboxhi0,iloboxhi1
     &           ,haslo
     &           ,ihiboxlo0,ihiboxlo1
     &           ,ihiboxhi0,ihiboxhi1
     &           ,hashi
     &           ,icenterboxlo0,icenterboxlo1
     &           ,icenterboxhi0,icenterboxhi1
     &           )

      implicit none
      integer CHF_ID(0:5,0:5)
      data CHF_ID/ 1,0,0,0,0,0 ,0,1,0,0,0,0 ,0,0,1,0,0,0 ,0,0,0,1,0,0 ,0,0,0,0,1,0 ,0,0,0,0,0,1 /


      integer iopphidirlo0,iopphidirlo1
      integer iopphidirhi0,iopphidirhi1
      REAL_T opphidir(
     &           iopphidirlo0:iopphidirhi0,
     &           iopphidirlo1:iopphidirhi1)
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1)
      REAL_T dx
      REAL_T beta
      integer idir
      integer iloboxlo0,iloboxlo1
      integer iloboxhi0,iloboxhi1
      integer haslo
      integer ihiboxlo0,ihiboxlo1
      integer ihiboxhi0,ihiboxhi1
      integer hashi
      integer icenterboxlo0,icenterboxlo1
      integer icenterboxhi0,icenterboxhi1
      integer i,j
      integer ioff,joff
      real_t bdx,bdx2
      bdx  = beta/dx
      bdx2 = bdx/dx
      
      ioff = chf_id(0,idir)
      joff = chf_id(1,idir)
      
      do j = icenterboxlo1,icenterboxhi1
      do i = icenterboxlo0,icenterboxhi0

      opphidir(i,j) =
     &     bdx2 *
     $     (    phi(i+ioff,j+joff)
     &     -two*phi(i     ,j     )
     &     +    phi(i-ioff,j-joff))
      
      enddo
      enddo
      if (haslo .eq. 1) then
         
      do j = iloboxlo1,iloboxhi1
      do i = iloboxlo0,iloboxhi0

         opphidir(i,j) =
     &        bdx *
     $        (  phi(i+ioff,j+joff)
     &        -  phi(i     ,j     ))
         
      enddo
      enddo
      endif
      if (hashi .eq. 1) then
         
      do j = ihiboxlo1,ihiboxhi1
      do i = ihiboxlo0,ihiboxhi0

         opphidir(i,j) =
     &        bdx *
     $        (  phi(i     ,j     )
     &        -  phi(i-ioff,j-joff))
         
      enddo
      enddo
      endif
      return
      end
        subroutine REGAPPLYDOMAINFLUX(
     &           opphidir
     &           ,iopphidirlo0,iopphidirlo1
     &           ,iopphidirhi0,iopphidirhi1
     &           ,faceflux
     &           ,ifacefluxlo0,ifacefluxlo1
     &           ,ifacefluxhi0,ifacefluxhi1
     &           ,dx
     &           ,beta
     &           ,idir
     &           ,side
     &           ,iloboxlo0,iloboxlo1
     &           ,iloboxhi0,iloboxhi1
     &           )

      implicit none
      integer iopphidirlo0,iopphidirlo1
      integer iopphidirhi0,iopphidirhi1
      REAL_T opphidir(
     &           iopphidirlo0:iopphidirhi0,
     &           iopphidirlo1:iopphidirhi1)
      integer ifacefluxlo0,ifacefluxlo1
      integer ifacefluxhi0,ifacefluxhi1
      REAL_T faceflux(
     &           ifacefluxlo0:ifacefluxhi0,
     &           ifacefluxlo1:ifacefluxhi1)
      REAL_T dx
      REAL_T beta
      integer idir
      integer side
      integer iloboxlo0,iloboxlo1
      integer iloboxhi0,iloboxhi1
        integer i,j
        real_t idx
        idx  = one/dx
        
      do j = iloboxlo1,iloboxhi1
      do i = iloboxlo0,iloboxhi0

        opphidir(i,j) = idx * side *
     &       (beta*faceflux(i,j) - opphidir(i,j))
        
      enddo
      enddo
        return
        end
      subroutine REGSUMLAPLACIAN(
     &           opphi
     &           ,iopphilo0,iopphilo1
     &           ,iopphihi0,iopphihi1
     &           ,opphidir
     &           ,iopphidirlo0,iopphidirlo1
     &           ,iopphidirhi0,iopphidirhi1
     &           ,iopphiboxlo0,iopphiboxlo1
     &           ,iopphiboxhi0,iopphiboxhi1
     &           )

      implicit none
      integer iopphilo0,iopphilo1
      integer iopphihi0,iopphihi1
      REAL_T opphi(
     &           iopphilo0:iopphihi0,
     &           iopphilo1:iopphihi1)
      integer iopphidirlo0,iopphidirlo1
      integer iopphidirhi0,iopphidirhi1
      REAL_T opphidir(
     &           iopphidirlo0:iopphidirhi0,
     &           iopphidirlo1:iopphidirhi1)
      integer iopphiboxlo0,iopphiboxlo1
      integer iopphiboxhi0,iopphiboxhi1
        integer i,j
        
      do j = iopphiboxlo1,iopphiboxhi1
      do i = iopphiboxlo0,iopphiboxhi0

        opphi(i,j) =
     $       opphi(   i,j) +
     $       opphidir(i,j)
        
      enddo
      enddo
        return
        end
        subroutine REGMULTICOLORGS(
     &           newphi
     &           ,inewphilo0,inewphilo1
     &           ,inewphihi0,inewphihi1
     &           ,weight
     &           ,resid
     &           ,iresidlo0,iresidlo1
     &           ,iresidhi0,iresidhi1
     &           ,icoloredboxlo0,icoloredboxlo1
     &           ,icoloredboxhi0,icoloredboxhi1
     &           )

      implicit none
      integer inewphilo0,inewphilo1
      integer inewphihi0,inewphihi1
      REAL_T newphi(
     &           inewphilo0:inewphihi0,
     &           inewphilo1:inewphihi1)
      REAL_T weight
      integer iresidlo0,iresidlo1
      integer iresidhi0,iresidhi1
      REAL_T resid(
     &           iresidlo0:iresidhi0,
     &           iresidlo1:iresidhi1)
      integer icoloredboxlo0,icoloredboxlo1
      integer icoloredboxhi0,icoloredboxhi1
        integer i,j
        
      do j = icoloredboxlo1,icoloredboxhi1,2
      do i = icoloredboxlo0,icoloredboxhi0,2

          newphi(i,j) = newphi(i,j)
     &                          + weight * resid(i,j)
        
      enddo
      enddo
        return
        end
      subroutine REGGSRB(
     &           newphi
     &           ,inewphilo0,inewphilo1
     &           ,inewphihi0,inewphihi1
     &           ,resid
     &           ,iresidlo0,iresidlo1
     &           ,iresidhi0,iresidhi1
     &           ,weight
     &           ,iboxlo0,iboxlo1
     &           ,iboxhi0,iboxhi1
     &           ,color
     &           )

      implicit none
      integer inewphilo0,inewphilo1
      integer inewphihi0,inewphihi1
      REAL_T newphi(
     &           inewphilo0:inewphihi0,
     &           inewphilo1:inewphihi1)
      integer iresidlo0,iresidlo1
      integer iresidhi0,iresidhi1
      REAL_T resid(
     &           iresidlo0:iresidhi0,
     &           iresidlo1:iresidhi1)
      REAL_T weight
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
      integer color
      integer i,j
      integer imin,imax,indtot
#if CH_SPACEDIM==3
      do k=iboxlo2, iboxhi2
#endif
#if CH_SPACEDIM > 1
         do j=iboxlo1, iboxhi1
#endif
            imin = iboxlo0
            indtot = imin + j 
            imin = imin + abs(mod(indtot + color, 2))
            imax = iboxhi0
            do i = imin, imax, 2
               newphi(i,j) = newphi(i,j)
     &                               + weight*resid(i,j)
            enddo
#if CH_SPACEDIM > 1
         enddo
#endif
#if CH_SPACEDIM==3
      enddo
#endif
      return
      end
      subroutine REGGETFLUX(
     &           flux
     &           ,ifluxlo0,ifluxlo1
     &           ,ifluxhi0,ifluxhi1
     &           ,nfluxcomp
     &           ,phi
     &           ,iphilo0,iphilo1
     &           ,iphihi0,iphihi1
     &           ,nphicomp
     &           ,iopphiboxlo0,iopphiboxlo1
     &           ,iopphiboxhi0,iopphiboxhi1
     &           ,beta
     &           ,dx
     &           ,idir
     &           ,ncomp
     &           )

      implicit none
      integer CHF_ID(0:5,0:5)
      data CHF_ID/ 1,0,0,0,0,0 ,0,1,0,0,0,0 ,0,0,1,0,0,0 ,0,0,0,1,0,0 ,0,0,0,0,1,0 ,0,0,0,0,0,1 /


      integer nfluxcomp
      integer ifluxlo0,ifluxlo1
      integer ifluxhi0,ifluxhi1
      REAL_T flux(
     &           ifluxlo0:ifluxhi0,
     &           ifluxlo1:ifluxhi1,
     &           0:nfluxcomp-1)
      integer nphicomp
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL_T phi(
     &           iphilo0:iphihi0,
     &           iphilo1:iphihi1,
     &           0:nphicomp-1)
      integer iopphiboxlo0,iopphiboxlo1
      integer iopphiboxhi0,iopphiboxhi1
      REAL_T beta
      REAL_T dx(0:1)
      integer idir
      integer ncomp
      integer i,j
      integer ioff,joff
      integer ivar
      real_t oneoverdx
      
      ioff = chf_id(0,idir)
      joff = chf_id(1,idir)
      oneoverdx = beta/dx(idir)
      do ivar = 0, ncomp-1
         
      do j = iopphiboxlo1,iopphiboxhi1
      do i = iopphiboxlo0,iopphiboxhi0

         flux(i,j, ivar) =
     $        oneoverdx*(
     $        phi(i     ,j     , ivar) -
     $        phi(i-ioff,j-joff, ivar) )
         
      enddo
      enddo
      enddo
      return
      end
