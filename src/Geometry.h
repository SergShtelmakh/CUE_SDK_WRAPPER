#pragma once

#include <CUESDK.h>

#include <QHash>
#include <QRect>

class Geometry
{
public:
	using Led = CorsairLedId;

	Geometry();

	QRect boundingRect() const;
	bool isEmpty() const;

	QList<Led> leds() const;
	QRect rect(const Led &key) const;

	void insert(const Led &key, const QRect &rect);

private:
	QHash<Led, QRect> m_geometry;
	QRect m_boundingRect;
};
