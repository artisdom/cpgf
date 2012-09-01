#ifndef __GSCRIPTSERVICE_H
#define __GSCRIPTSERVICE_H


#include "cpgf/gapi.h"


namespace cpgf {

class GScriptObject;
struct IMetaClass;

class GScriptCoreService
{
public:
	~GScriptCoreService();
	
private:
	explicit GScriptCoreService(GScriptObject * scriptObject);

	IMetaClass * cloneClass(IMetaClass * metaClass);

private:
	GScriptObject * scriptObject;
	GScopedInterface<IMetaClass> previousClonedMetaClass;

private:
	friend GScriptCoreService * doCreateScriptCoreService(GScriptObject * scriptObject);

	template <typename D>
	friend void buildMetaClass_GScriptCoreService(D _d);
};



} // namespace cpgf



#endif