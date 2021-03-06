        subroutine SETDIRICHLETFACEFLUX(
     & faceFlux
     & ,ifaceFluxlo0,ifaceFluxlo1
     & ,ifaceFluxhi0,ifaceFluxhi1
     & ,phi
     & ,iphilo0,iphilo1
     & ,iphihi0,iphihi1
     & ,value
     & ,dx
     & ,idir
     & ,iside
     & ,iboxlo0,iboxlo1
     & ,iboxhi0,iboxhi1
     & )
      implicit none
      integer ifaceFluxlo0,ifaceFluxlo1
      integer ifaceFluxhi0,ifaceFluxhi1
      REAL*8 faceFlux(
     & ifaceFluxlo0:ifaceFluxhi0,
     & ifaceFluxlo1:ifaceFluxhi1)
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL*8 phi(
     & iphilo0:iphihi0,
     & iphilo1:iphihi1)
      REAL*8 value
      REAL*8 dx(0:1)
      integer idir
      integer iside
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
        integer i,j
        REAL*8 ihdx
        ihdx = (2.0d0)/dx(idir)
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0
          faceFlux(i,j) = iside * ihdx * (phi(i,j) - value)
      enddo
      enddo
        return
        end
        subroutine SETHODIRICHLETFACEFLUX(
     & faceFlux
     & ,ifaceFluxlo0,ifaceFluxlo1
     & ,ifaceFluxhi0,ifaceFluxhi1
     & ,phi
     & ,iphilo0,iphilo1
     & ,iphihi0,iphihi1
     & ,value
     & ,dx
     & ,idir
     & ,iside
     & ,iboxlo0,iboxlo1
     & ,iboxhi0,iboxhi1
     & )
      implicit none
      integer CHF_ID(0:5,0:5)
      data CHF_ID/ 1,0,0,0,0,0 ,0,1,0,0,0,0 ,0,0,1,0,0,0 ,0,0,0,1,0,0 ,0
     &,0,0,0,1,0 ,0,0,0,0,0,1 /
      integer ifaceFluxlo0,ifaceFluxlo1
      integer ifaceFluxhi0,ifaceFluxhi1
      REAL*8 faceFlux(
     & ifaceFluxlo0:ifaceFluxhi0,
     & ifaceFluxlo1:ifaceFluxhi1)
      integer iphilo0,iphilo1
      integer iphihi0,iphihi1
      REAL*8 phi(
     & iphilo0:iphihi0,
     & iphilo1:iphihi1)
      REAL*8 value
      REAL*8 dx(0:1)
      integer idir
      integer iside
      integer iboxlo0,iboxlo1
      integer iboxhi0,iboxhi1
        integer i,j, ioff,joff
        REAL*8 dxinv
        ioff = iside*chf_id(0,idir)
                  joff = iside*chf_id(1,idir)
        dxinv = (1.0d0)/dx(idir)
      do j = iboxlo1,iboxhi1
      do i = iboxlo0,iboxhi0
          faceFlux(i,j) =
     & iside * dxinv * ((3.0d0)*phi(i,j)
     & - (1.0d0)/(3.0d0)*phi(i+ioff,j+joff)
     & - (8.0d0)/(3.0d0)*value)
      enddo
      enddo
        return
        end
