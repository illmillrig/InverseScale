
#include "InverseScale.h"

#include <maya/MPlug.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MGlobal.h>
#include <maya/MFnMatrixAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MFnEnumAttribute.h>
#include <maya/MVector.h>


MTypeId InverseScale::id(0x001226D1);
MObject InverseScale::inScaleX;
MObject InverseScale::inScaleY;
MObject InverseScale::inScaleZ;
MObject InverseScale::inScale;
MObject InverseScale::outScaleX;
MObject InverseScale::outScaleY;
MObject InverseScale::outScaleZ;
MObject InverseScale::outScale;

InverseScale::InverseScale() {}

InverseScale::~InverseScale() {}

void* InverseScale::creator() {
	return new InverseScale();
}

MStatus InverseScale::initialize() {
	// attributes are writable by default
	// attributes are storable by default
	// attributes are readable by default
	// attributes not keyable by default
	MStatus stat;
	MFnNumericAttribute fnNum;
	MFnMatrixAttribute fnMat;
	MFnUnitAttribute fnUnit;
	MFnEnumAttribute fnEnum;

	inScaleX = fnNum.create("inScaleX", "isx", MFnNumericData::kDouble, 1.0, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setKeyable(true);

	inScaleY = fnNum.create("inScaleY", "isy", MFnNumericData::kDouble, 1.0, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setKeyable(true);

	inScaleZ = fnNum.create("inScaleZ", "isz", MFnNumericData::kDouble, 1.0, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setKeyable(true);

	inScale = fnNum.create("inScale", "is", inScaleX, inScaleY, inScaleZ, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setKeyable(true);
	stat = InverseScale::addAttribute(inScale);
	CHECK_MSTATUS(stat);


	// outputs
	outScaleX = fnNum.create("outScaleX", "osx", MFnNumericData::kDouble, 1.0, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setStorable(false);
	fnNum.setWritable(false);

	outScaleY = fnNum.create("outScaleY", "osy", MFnNumericData::kDouble, 1.0, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setStorable(false);
	fnNum.setWritable(false);

	outScaleZ = fnNum.create("outScaleZ", "osz", MFnNumericData::kDouble, 1.0, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setStorable(false);
	fnNum.setWritable(false);

	outScale = fnNum.create("outScale", "os", outScaleX, outScaleY, outScaleZ, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setStorable(false);
	fnNum.setWritable(false);
	stat = InverseScale::addAttribute(outScale);
	CHECK_MSTATUS(stat);


	// affects
	InverseScale::attributeAffects(inScale, outScale);

	return MS::kSuccess;
}


MStatus InverseScale::compute(const MPlug &plug, MDataBlock &data) {

	double3 &inScale = data.inputValue(InverseScale::inScale).asDouble3();

	data.outputValue(InverseScale::outScaleX).set3Double( 1.0/inScale[0], 1.0/inScale[1], 1.0/inScale[2] );

	data.setClean(InverseScale::outScale);
	return MS::kSuccess;
}


























