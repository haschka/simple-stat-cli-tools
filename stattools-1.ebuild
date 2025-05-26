# Distributed under the terms of the GNU General Public License v3

EAPI=8

inherit toolchain-funcs git-r3

DESCRIPTION="simple statistic tools"
HOMEPAGE="https://github.com/haschka/simple-stat-cli-tools"
EGIT_REPO_URI="https://github.com/haschka/simple-stat-cli-tools"

SLOT="0"
KEYWORDS="amd64 ~x86 ~ppc"
IUSE=""

src_compile() {
        $(tc-getCC) ${CFLAGS} histogram.c -o histogram
	$(tc-getCC) ${CFLAGS} mean.c -o mean
	$(tc-getCC) ${CFLAGS} stddev.c -o stddev -lm
}

src_install() {
        dobin histogram
	dobin mean
	dobin stddev
}
