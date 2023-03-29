#pragma once
#include <tuple>

class Size {
public:
	Size(double width, double height)
		: width(width),
		height(height) {}

	int getWidth() {
		return width;
	}

	int getHeigth() {
		return height;
	}

	void setWidth(double weigth)
	{
		this->width = weigth;
	}

	void setHeigth(double heigth)
	{
		this->height = heigth;
	}

	friend bool operator==(const Size& lhs, const Size& rhs)
	{
		return std::tie(lhs.width, lhs.height) == std::tie(rhs.width, rhs.height);
	}

private:
	double width;
	double height;
};