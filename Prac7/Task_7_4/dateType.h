#ifndef date_H
#define date_H
    
class dateType
{
public:
    void setDate(int month, int day, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void printDate() const;
    dateType(int day = 1, int month = 1,  int year = 2000);

private:
    int dDay;        //variable to store the day
    int dMonth;      //variable to store the month
    int dYear;       //variable to store the year
};

void dateType::setDate(int day, int month,  int year)
{
    dDay = day;
    dMonth = month;
    dYear = year;
}

int dateType::getDay() const
{
    return dDay;
}

int dateType::getMonth() const
{
    return dMonth;
}

int dateType::getYear() const
{
    return dYear;
}

void dateType::printDate() const
{
    cout << dDay << "-" << dMonth << "-"  <<dYear;
}

	//constructor with parameter
dateType::dateType(int day, int month, int year)
{
	dDay = day;
	dMonth = month;
	dYear = year;
}
#endif
