#include "CueSdkWrapper.h"

class CueSdkWrapper::Impl
{
public:
	Impl()
	{
		CorsairPerformProtocolHandshake();
		CorsairRequestControl(CAM_ExclusiveLightingControl);
	}

	~Impl()
	{
		CorsairReleaseControl(CAM_ExclusiveLightingControl);
	}
};

CueSdkWrapper::CueSdkWrapper()
    : m_pImpl(new Impl)
{
}

CueSdkWrapper::~CueSdkWrapper()
{
}

void CueSdkWrapper::reset()
{
	m_pImpl.reset(new Impl);
}

Geometry CueSdkWrapper::getGeometry() const
{
	auto pos = CorsairGetLedPositions();
	if (!pos) {
		return {};
	}

	auto it = pos->pLedPosition;

	Geometry geom;
	for (auto i = 0; i < pos->numberOfLed; ++i) {
		CorsairLedPosition p = *it;
		geom.insert(p.ledId, QRect(p.left, p.top, p.width, p.height));
		++it;
	}

	return geom;
}

void CueSdkWrapper::setFrame(const Lighting::Frame &frame)
{
	auto nonConstFrame = frame;
	CorsairSetLedsColors(nonConstFrame.size(), nonConstFrame.data());
}
