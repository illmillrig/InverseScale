#pragma once

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MTypeId.h> 


class InverseScale : public MPxNode {
public:
	InverseScale();
	virtual ~InverseScale();
	static void* creator();
	static MStatus initialize();
	virtual MStatus compute( const MPlug& plug, MDataBlock& data );
public:
	static MTypeId id;

	static MObject inScaleX;
	static MObject inScaleY;
	static MObject inScaleZ;
	static MObject inScale;

	static MObject outScaleX;
	static MObject outScaleY;
	static MObject outScaleZ;
	static MObject outScale;

};
