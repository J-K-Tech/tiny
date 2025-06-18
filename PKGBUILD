pkgname=tiny
pkgver=1.0
pkgrel=1
pkgdesc="tiny script runner"
arch=('x86_64')
url="https://crystalsoft.neocities.org"
license=('AGPL3')
makedepends=('gcc')
source=("https://github.com/J-K-Tech/${pkgname}/archive/refs/tags/${pkgver}.tar.gz")
sha256sums=('SKIP')

build() {
    g++ -O3 term.cpp main.cpp -o tiny
}

package() {
    install -Dm755 tiny "$pkgdir/tiny"
}