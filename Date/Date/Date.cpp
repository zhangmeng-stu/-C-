#include "Date.h"

Date::Date(int year , int month , int day )
:_year(year)
, _month(month)
, _day(day)
{}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

}
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}
	return *this;
}
bool Isleapyear(int year)
{
	if ((year % 4 == 0 || year % 100 != 0) && (year % 400 == 0))
	{
		return true;
	}
	return false;
}
int Dayofmonth(int year, int month)
{
	int days[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (month == 2 && Isleapyear(year))
	{
		days[month] += 1;
	}
	return days[month];
}
Date Date::operator+(int days)
{
	if (days < 0)
	{
		return *this - (0 - days);
	}
	Date d = *this;
	d._day = d._day + days;
	while (d._day > Dayofmonth(d._year, d._month))
	{
		d._day -= Dayofmonth(d._year, d._month);
		d._month++;
		if (d._month>12)
		{
			d._year++;
			d._month = 1;
		}
	}
	return d;
}
Date Date:: operator-(int days)
{
	if (days < 0)
	{
		return *this + (-days);
	}
	Date d = *this;
	d._day = d._day - days;
	while (d._day < 0)
	{
		d._month--;
		d._day += Dayofmonth(d._year, d._month);
		if (d._month < 0)
		{
			d._year--;
			d._month = 12;
		}
	}
	return d;
}
int Date::operator-(const Date& d)
{
	Date Min = *this;
	Date Max = d;
	if (*this > d)
	{
		Min = d;
		Max = *this;
	}
	int count = 0;
	while (Min != Max)
	{
		count++;
		++Min._day;
	}
	return count;
}
Date& Date:: operator++()
{	
	*this = *this + 1;
	return *this;
}
Date Date::operator++(int)
{
	Date Temp(*this);
	*this = *this + 1;
	return Temp;
}
Date& Date:: operator--()
{
	*this = *this - 1;
	return *this;
}
Date Date::operator--(int)
{
	Date Temp(*this);
	*this = *this - 1;
	return Temp;
}
bool Date:: operator>(const Date& d)const
{
	return _year > d._year ||
		(_year == d._year && _month > d._month) ||
		(_year == d._year && _month == d._month && _day > d._day);
}
bool Date::operator>=(const Date& d)const
{
	return (*this > d) || (*this == d);
}
bool Date::operator<(const Date& d)const
{
	return _year < d._year ||
		(_year == d._year && _month < d._month) ||
		(_year == d._year && _month == d._month && _day < d._day);
}
bool Date::operator<=(const Date& d)const
{
	return !(*this>d);
}
bool Date::operator==(const Date& d)const
{
	if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	return false;
}
bool Date::operator!=(const Date& d)const
{
	if (!(_year == d._year && _month == d._month && _day < d._day))
	{
		return true;
	}
	return false;
}
 ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}