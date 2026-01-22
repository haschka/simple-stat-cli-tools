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
	$(tc-getCC) ${CFLAGS} median.c -o median
	$(tc-getCC) ${CFLAGS} stddev.c -o stddev -lm
	$(tc-getCC) ${CFLAGS} percentile.c -o percentile -lm 
	$(tc-getCC) ${CFLAGS} random_sample.c -o random_sample
	$(tc-getCC) ${CFLAGS} correlate.c -o correlate -lm
	$(tc-getCC) ${CFLAGS} cossimilarity.c -o cossimilarity -lm
	$(tc-getCC) ${CFLAGS} linearregression.c -o linearregression
	$(tc-getCC) ${CFLAGS} maximum.c -o maximum
	$(tc-getCC) ${CFLAGS} minimum.c -o minimum
}

src_install() {
        dobin histogram
	dobin mean
	dobin median
	dobin stddev
	dobin percentile
	dobin random_sample
	dobin cossimilarity
	dobin correlate
	dobin linearregression
	dobin maximum
	dobin minimum
}
