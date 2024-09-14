#pragma once

#include "layout.h"

namespace dea::layout
{

class ContraintLayout : public Layout
{
public:
	void layout() override;
	void add(const document::EditRecordItem* record);
private:
};	

} // namespace dea::layout
