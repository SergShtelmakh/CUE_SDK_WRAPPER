#pragma once

#include "Geometry.h"
#include "Lighting.h"

#include <QScopedPointer>

class CueSdkWrapper
{
public:
	explicit CueSdkWrapper();
	~CueSdkWrapper();

	void reset();

	Geometry getGeometry() const;

	void setFrame(const Lighting::Frame &frame);

private:
	class Impl;
	QScopedPointer<Impl> m_pImpl;
};

