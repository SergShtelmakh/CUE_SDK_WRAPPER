#include "Lighting.h"

Lighting::Lighting()
{
}

Lighting::~Lighting()
{
}

bool Lighting::empty() const
{
	return m_data.empty();
}

size_t Lighting::size() const
{
	return m_data.size();
}

void Lighting::append(Lighting::Frame &&frame)
{
	m_data.push_back(std::move(frame));
}

const Lighting::Frame &Lighting::operator [](size_t index) const
{
	Q_ASSERT(index >= 0 && index < m_data.size());
	return m_data[index];
}
