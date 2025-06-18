pkgname=tiny
pkgver=1.0
pkgrel=1
pkgdesc="tiny script runner"
arch=('x86_64')
url="https://example.com"
license=('AGPLv3')
depends=('bash')
makedepends=('cmake' 'gcc')
source=("https://github.com/J-K-Tech/${pkgname}/archive/refs/tags/${pkgver}.tar.gz")
sha256sums=('SKIP')  # Change to proper checksum later

build() {
  cd "$srcdir/$pkgname-$pkgver"
  cmake -DCMAKE_INSTALL_PREFIX=/usr .
  make
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  make DESTDIR="$pkgdir/" install

  # ✅ Install the license manually if upstream doesn’t
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
