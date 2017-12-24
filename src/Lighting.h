#pragma once

#include <CUESDK.h>

#include <QVector>

class Lighting
{
public:
	using Frame = QVector<CorsairLedColor>;

public:
	Lighting();
	~Lighting();

	bool empty() const;
	size_t size() const;

	void append(Frame &&frame);

	const Lighting::Frame &operator [](size_t index) const;

private:
	QVector<Frame> m_data;
};
