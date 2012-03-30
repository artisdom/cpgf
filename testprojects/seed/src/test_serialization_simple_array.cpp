#include "testserializationcommon.h"
#include "testserializationcommonclasses.h"
#include "cpgf/gmetadefine.h"

#include "gmetatextstreamarchive.h"

#include <sstream>
#include <string>

#include <iostream>

using namespace std;
using namespace cpgf;


namespace {

template <typename AR>
void doTestSimpleArray(IMetaWriter * writer, IMetaReader * reader, const AR & ar)
{
	GScopedInterface<IMetaArchiveWriter> archiveWriter(createMetaArchiveWriter(GMetaArchiveConfig().getFlags(), NULL, writer));

	enum {
		A = 3, B = 5, C = 38, D = 50, E = 51, F = 58, G = 60, H = 61, I = 66, J = 68, K = 10, L = 15, M = 18, N = 20, O = 25, P = 28, Q = 2
	};

	bool b[A];
	char c[B];
	wchar_t wc[C];
	signed char sc[D];
	unsigned char uc[E];
	short si[F];
	unsigned short usi[G];
	int i[H];
	unsigned int ui[I];
	long l[J];
	unsigned long ul[K];
	long long ll[L];
	unsigned long long ull[M];
	float f[N];
	double df[O];
	long double ldf[P];
	string s[Q];
	string * ps[Q];

#define INIT(v, l) for(int z = 0; z < l; ++z) initTestValue(v[z], getTestSeed(z + 1));
	INIT(b, A)
	INIT(c, B)
	INIT(wc, C)
	INIT(sc, D)
	INIT(uc, E)
	INIT(si, F)
	INIT(usi, G)
	INIT(i, H)
	INIT(ui, I)
	INIT(l, J)
	INIT(ul, K)
	INIT(ll, L)
	INIT(ull, M)
	INIT(f, N)
	INIT(df, O)
	INIT(ldf, P)
	INIT(s, Q)
#undef INIT

#define INIT(v, l) for(int z = 0; z < l; ++z) ps[z] = &s[z];
	INIT(ps, Q)
#undef INIT

	serializeWriteValue(archiveWriter.get(), "b", b);
	serializeWriteValue(archiveWriter.get(), "c", c);
	serializeWriteValue(archiveWriter.get(), "wc", wc);
	serializeWriteValue(archiveWriter.get(), "sc", sc);
	serializeWriteValue(archiveWriter.get(), "uc", uc);
	serializeWriteValue(archiveWriter.get(), "si", si);
	serializeWriteValue(archiveWriter.get(), "usi", usi);
	serializeWriteValue(archiveWriter.get(), "i", i);
	serializeWriteValue(archiveWriter.get(), "ui", ui);
	serializeWriteValue(archiveWriter.get(), "l", l);
	serializeWriteValue(archiveWriter.get(), "ul", ul);
	serializeWriteValue(archiveWriter.get(), "ll", ll);
	serializeWriteValue(archiveWriter.get(), "ull", ull);
	serializeWriteValue(archiveWriter.get(), "f", f);
	serializeWriteValue(archiveWriter.get(), "df", df);
	serializeWriteValue(archiveWriter.get(), "ldf", ldf);
	serializeWriteValue(archiveWriter.get(), "s", s);
	serializeWriteValue(archiveWriter.get(), "ps", ps);

	ar.rewind();

	GScopedInterface<IMetaArchiveReader> archiveReader(createMetaArchiveReader(GMetaArchiveConfig().getFlags(), NULL, reader));

	bool rb[A];
	char rc[B];
	wchar_t rwc[C];
	signed char rsc[D];
	unsigned char ruc[E];
	short rsi[F];
	unsigned short rusi[G];
	int ri[H];
	unsigned int rui[I];
	long rl[J];
	unsigned long rul[K];
	long long rll[L];
	unsigned long long rull[M];
	float rf[N];
	double rdf[O];
	long double rldf[P];
	string rs[Q];
	string * rps[Q];

#define INIT(v, l) for(int z = 0; z < l; ++z) initTestValue(v[z], getTestSeed(0));
	INIT(rb, A)
	INIT(rc, B)
	INIT(rwc, C)
	INIT(rsc, D)
	INIT(ruc, E)
	INIT(rsi, F)
	INIT(rusi, G)
	INIT(ri, H)
	INIT(rui, I)
	INIT(rl, J)
	INIT(rul, K)
	INIT(rll, L)
	INIT(rull, M)
	INIT(rf, N)
	INIT(rdf, O)
	INIT(rldf, P)
	INIT(rs, Q)
#undef INIT

#define INIT(v, l) for(int z = 0; z < l; ++z) v[z] = NULL;
	INIT(rps, Q)
#undef INIT


	serializeReadValue(archiveReader.get(), "rb", rb);
	serializeReadValue(archiveReader.get(), "rc", rc);
	serializeReadValue(archiveReader.get(), "rwc", rwc);
	serializeReadValue(archiveReader.get(), "rsc", rsc);
	serializeReadValue(archiveReader.get(), "ruc", ruc);
	serializeReadValue(archiveReader.get(), "rsi", rsi);
	serializeReadValue(archiveReader.get(), "rusi", rusi);
	serializeReadValue(archiveReader.get(), "ri", ri);
	serializeReadValue(archiveReader.get(), "rui", rui);
	serializeReadValue(archiveReader.get(), "rl", rl);
	serializeReadValue(archiveReader.get(), "rul", rul);
	serializeReadValue(archiveReader.get(), "rll", rll);
	serializeReadValue(archiveReader.get(), "rull", rull);
	serializeReadValue(archiveReader.get(), "rf", rf);
	serializeReadValue(archiveReader.get(), "rdf", rdf);
	serializeReadValue(archiveReader.get(), "rldf", rldf);
	serializeReadValue(archiveReader.get(), "rs", rs);
	serializeReadValue(archiveReader.get(), "rps", rps);

#define EQ(v, u, l) for(int z = 0; z < l; ++z) GEQUAL(v[z], u[z]);
	EQ(b, rb, A)
	EQ(c, rc, B)
	EQ(wc, rwc, C)
	EQ(sc, rsc, D)
	EQ(uc, ruc, E)
	EQ(si, rsi, F)
	EQ(usi, rusi, G)
	EQ(i, ri, H)
	EQ(ui, rui, I)
	EQ(l, rl, J)
	EQ(ul, rul, K)
	EQ(ll, rll, L)
	EQ(ull, rull, M)
	EQ(s, rs, Q)
#undef EQ

#define EQ(v, u, l) for(int z = 0; z < l; ++z) GCHECK(fabs(v[z] - u[z]) < 0.1);
	EQ(f, rf, N)
	EQ(df, rdf, O)
	EQ(ldf, rldf, P)
#undef EQ

#define EQ(v, u, l) for(int z = 0; z < l; ++z) GEQUAL(&v[z], u[z]);
	EQ(rs, rps, Q)
#undef EQ

}

GTEST(testSimpleArray)
{
	stringstream stream;

	GTextStreamMetaWriter<stringstream> outputStream(stream);
	GTextStreamMetaReader<stringstream> inputStream(NULL, stream);
	
	doTestSimpleArray(&outputStream, &inputStream, TestArchiveStream<stringstream>(stream));
	
//	cout << stream.str().c_str() << endl;
}


} // unnamed namespace
