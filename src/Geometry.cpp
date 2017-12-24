#include "Geometry.h"

Geometry::Geometry()
{
}

QRect Geometry::boundingRect() const
{
	return m_boundingRect;
}

bool Geometry::isEmpty() const
{
	return m_geometry.empty();
}

QList<Geometry::Led> Geometry::leds() const
{
	return m_geometry.keys();
}

QRect Geometry::rect(const Geometry::Led &key) const
{
	Q_ASSERT(m_geometry.contains(key));
	return m_geometry.value(key);
}

void Geometry::insert(const Geometry::Led &key, const QRect &value)
{
	Q_ASSERT(!m_geometry.contains(key));

	m_geometry.insert(key, value);

	m_boundingRect.setLeft(qMin(m_boundingRect.left(), value.left()));
	m_boundingRect.setRight(qMax(m_boundingRect.right(), value.right()));
	m_boundingRect.setTop(qMin(m_boundingRect.top(), value.top()));
	m_boundingRect.setBottom(qMax(m_boundingRect.bottom(), value.bottom()));

	Q_ASSERT(m_boundingRect.contains(value.center()));
}
