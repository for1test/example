#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int DD, MM, YYYY, hh, mm, et;
int masterCnt = 0;
bool eventValid = true;

class Chevent
{   //Class Function for storing different function
public:
	void Eventtitle(string &title)
	{   //Check the event title
		// Event Title
		int length = title.length();
		if (length <= 40)
			event_title = title;
		else
			eventValid = false;
	}

	void eDate(int &DD, int &MM, int &YYYY)   //Check the event date
	{
		if (YYYY > 999 && YYYY <= 9999) {
			if (MM > 0 && MM < 13) {
				if (MM == 1 || MM == 3 || MM == 5 || MM == 7 || MM == 8 || MM == 10 || MM == 12) {
					if (DD > 0 && DD < 32) {
						eventValid = true;
					} else {
						eventValid = false;
					}
				} else if (MM == 4 || MM == 6 || MM == 9 || MM == 11) {
					if (DD > 0 && DD < 31) {
						eventValid = true;
					} else {
						eventValid = false;
					}
				} else if (MM == 2) {
					if ((YYYY % 4 == 0 && YYYY % 100 != 0) || YYYY % 400 == 0) {
						if (DD > 0 && DD < 30) {
							eventValid = true;
						} else {
							eventValid = false;
						}
					} else if (DD > 0 && DD < 29) {
						eventValid = true;
					} else {
						eventValid = false;
					}
				}
			} else {
				eventValid = false;
			}
		} else {
			eventValid = false;
		}
		if (eventValid == true) {
			dd = DD;
			mm = MM;
			yyyy = YYYY;
		}
	}

	void askDate(string &date, int &DD, int &MM, int &YYYY)   //for all cin date situation
	{
		cout << "Please Enter the Event Day (DD-MM-YYYY) or (DD MM YYYY): ";
		getline(cin, date);
		cout << endl;
		try {
			if (date.at(2) != ' ' && date.at(2) != '-' && date.at(5) != ' ' && date.at(5) != '-')
				eventValid = false;
			DD = stoi(date.substr(0, 2));
			MM = stoi(date.substr(3, 2));
			YYYY = stoi(date.substr(6, 5));
			eDate(DD, MM, YYYY);
		} catch (...) {
			eventValid = false;
		}
	}

	void etype(int &et)   //check the event type
	{
		(et < 5 && et > 0) ? realEt = et : eventValid = false;
	}

	void askSTime(string &time, int &hh, int &mm)   //for cin start time  situation
	{
		cout << "Please Enter the start time (hh:mm) or (hh mm): ";
		getline(cin, time);
		cout << endl;

		try {
			if (time.at(2) != ' ' && time.at(2) != ':')
				eventValid = false;
			hh = stoi(time.substr(0, 2));
			mm = stoi(time.substr(3, 2));
			Checkstartime(hh, mm);
		} catch (...) {
			eventValid = false;
		}
	}

	void askETime(string &time, int &hh, int &mm)   //for cin end time  situation
	{
		cout << "Please Enter the end time (hh:mm) or (hh mm): ";
		getline(cin, time);
		cout << endl;
		try {
			if (time.at(2) != ' ' && time.at(2) != ':')
				eventValid = false;
			hh = stoi(time.substr(0, 2));
			mm = stoi(time.substr(3, 2));
			Checkendtime(hh, mm);
		} catch (...) {
			eventValid = false;
		}
	}

	void Checkstartime(int &hh, int &mm)   //Check start time
	{
		if ((hh >= 0 && hh <= 23) && (mm >= 0 && mm <= 59)) {
			shh = hh;
			smm = mm;
		} else {
			eventValid = false;
		}
	}

	void Checkendtime(int &hh, int &mm)   //Check end time
	{
		if ((hh >= 0 && hh <= 23) && (mm >= 0 && mm <= 59)) {
			ehh = hh;
			emm = mm;
		} else {
			eventValid = false;
		}
	}

	void showTable()   //Show all the information about the event
	{
		(dd < 10) ? cout << left << "0" << dd << "-" : cout << left << dd << "-";
		(mm < 10) ? cout << "0" << mm << '-' << yyyy << ',' : cout << mm << '-' << yyyy << ',';
		if (shh <= 24 && shh >= 0 && smm <= 60 && smm >= 0) {
			(shh < 10) ? cout << '0' << shh << ":" : cout << shh << ":";
			(smm < 10) ? cout << '0' << smm << '-' : cout << smm << '-';
		}
		if (ehh <= 24 && ehh >= 0 && emm <= 60 && emm >= 0) {
			(ehh < 10) ? cout << '0' << ehh << ":" : cout << ehh << ":";
			(emm < 10) ? cout << '0' << emm << "   " : cout << emm << "   ";
		}
		cout << setw(45) << event_title;
		switch (realEt) {
		case 1:
			cout << setw(5) << "Home" << endl;
			break;
		case 2:
			cout << setw(5) << "Work" << endl;
			break;
		case 3:
			cout << setw(5) << "Study" << endl;
			break;
		case 4:
			cout << setw(5) << "Play" << endl;
			break;
		}
	}

	void getDate(int &temd, int &temm, int &temy)   //get the date
	{
		temd = dd;
		temm = mm;
		temy = yyyy;
	}
	void getStartime(int &temsh, int &temsm)   //get the start time
	{
		temsh = shh;
		temsm = smm;
	}
	void getEndtime(int &temeh, int &temem)   //get the end time
	{
		temeh = ehh;
		temem = emm;
	}
	void gettype(int &tet)   //get the event type
	{
		tet = realEt;
	}
	string getTitle() const   //get the event title
	{
		return event_title;
	}
	void calPrint()   //print time period in calendar
	{
		if (shh <= 24 && shh >= 0 && smm <= 60 && smm >= 0) {
			(shh < 10) ? cout << '0' << shh << ":" : cout << shh << ":";
			(smm < 10) ? cout << '0' << smm << '-' : cout << smm << '-';
		}
		if (ehh <= 24 && ehh >= 0 && emm <= 60 && emm >= 0) {
			(ehh < 10) ? cout << '0' << ehh << ":" : cout << ehh << ":";
			(emm < 10) ? cout << '0' << emm << " " : cout << emm << " ";
		}
	}

private:
	string event_title;
	int dd = 0, mm = 0, yyyy = 0, shh = 0, smm = 0, ehh = 0, emm = 0, realEt = 0;
};

Chevent C[103];

void SetColor(int color = 7)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void splitStr(string &input, string &temTit, int &temD, int &temM, int &temY, int &temh, int &temm, int &temTyp)
{
	temD = stoi(input.substr(0, 2));
	temM = stoi(input.substr(3, 2));
	temY = stoi(input.substr(6, 4));
	temh = stoi(input.substr(11, 2));
	temm = stoi(input.substr(14, 2));
	C[masterCnt].Checkstartime(temh, temm);
	temh = stoi(input.substr(17, 2));
	temm = stoi(input.substr(20, 2));
	C[masterCnt].Checkendtime(temh, temm);
	input.erase(0, 23);
	size_t pos = input.rfind('/');
	temTyp = stoi(input.substr(pos + 1, 1));
	input.erase(pos, 2);
	temTit = input;
}

bool checkLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;
	else
		return false;
}

int comparedate(int &vdd, int &vmm, int &vyyyy)   //function day / month / year for comparing
{
	for (int i = 0; i < masterCnt; i++) {
		C[i].getDate(DD, MM, YYYY);
		if (DD == vdd && MM == vmm && YYYY == vyyyy)   // comparing R2 and R1 day
		{
			return i;
		}
	}
	return -1;
}

int comparedate2()   //function day / month / year for comparing
{
	int ddt, mmt, yyyyt, ddn, mmn, yyyyn, shh, smm, hht, mt, hhn, mn;
	for (int i = 0; i < masterCnt; i++) {
		C[i].getDate(DD, MM, YYYY);
		C[101].getDate(ddt, mmt, yyyyt);
		C[102].getDate(ddn, mmn, yyyyn);
		C[i].getStartime(shh, smm);
		C[101].getStartime(hht, mt);
		C[102].getStartime(hhn, mn);
		if ((!(YYYY < yyyyt || (YYYY == yyyyt && MM < mmt) || (YYYY == yyyyt && MM == mmt && DD < ddt) || (YYYY == yyyyt && MM == mmt && DD == ddt && shh < hht) || (YYYY == yyyyt && MM == mmt && DD == ddt && shh == hht && smm < mt))) && (!(YYYY > yyyyn || (YYYY == yyyyn && MM > mmn) || (YYYY == yyyyn && MM == mmn && DD > ddn) || (YYYY == yyyyn && MM == mmn && DD == ddn && shh > hhn) || (YYYY == yyyyn && MM == mmn && DD == ddn && shh == hhn && smm > mn)))) {
			return i;
		}
	}
	return -1;
}

bool compare(Chevent &d1, Chevent &d2)   // function that use with sort() function
{
	int vdd, vmm, vyyyy, hh2, mm2;
	d1.getDate(DD, MM, YYYY);
	d2.getDate(vdd, vmm, vyyyy);
	d1.getStartime(hh, mm);
	d2.getStartime(hh2, mm2);
	if (YYYY < vyyyy)
		return true;
	else if (YYYY == vyyyy && MM < vmm) {
		return true;
	} else if (YYYY == vyyyy && MM == vmm && DD < vdd) {
		return true;
	} else if (YYYY == vyyyy && MM == vmm && DD == vdd && hh < hh2) {
		return true;
	} else if (YYYY == vyyyy && MM == vmm && DD == vdd && hh == hh2 && mm < mm2) {
		return true;
	}
	return false;
}

void checktimeconflict()   // for all situatuin to check the conflict
{
	int shh, smm, shh2, smm2, ehh, emm, ehh2, emm2, vdd, vmm, vyyyy;
	for (int i = 0; i < masterCnt; ++i) {
		C[masterCnt].getDate(DD, MM, YYYY);
		C[i].getDate(vdd, vmm, vyyyy);
		C[masterCnt].getStartime(shh, smm);
		C[i].getStartime(shh2, smm2);
		C[masterCnt].getEndtime(ehh, emm);
		C[i].getEndtime(ehh2, emm2);
		if (YYYY == vyyyy && MM == vmm && DD == vdd) {
			if (!(((shh < shh2) || (shh == shh2 && smm <= smm2)) && ((ehh < shh2) || (ehh == shh2 && emm <= smm2)))) {
				if (!(((shh > ehh2) || (shh == ehh2 && smm >= emm2)) && ((ehh < 23) || (ehh == 23 && emm <= 59))))
					eventValid = false;
			}
		} else
			eventValid = true;
	}
}

void checktimeconflict2()   //check the start time and end time are not impact
{
	int shh, smm, ehh, emm;
	C[masterCnt].getStartime(shh, smm);
	C[masterCnt].getEndtime(ehh, emm);
	if (!((shh < ehh) || (shh == ehh && smm < emm))) {
		eventValid = false;
	} else
		eventValid = true;
}

void S1()
{
	sort(C, C + masterCnt, compare);
	C[0].getDate(DD, MM, YYYY);
	if (YYYY == 0)
		cout << "You don't have any event yet." << endl;
	else {
		cout << left << setw(25) << "Date and Time" << setw(45) << "Title" << setw(5) << "Type" << endl;
		for (int i = 0; i < masterCnt; ++i)
			C[i].showTable();
	}
}

void Today(int &DD, int &MM, int &YYYY, int &hh, int &mm, int &n)   // save today as event object in C[101]
{
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	string str(buffer);
	DD = stoi(str.substr(0, 2));
	MM = stoi(str.substr(3, 2));
	YYYY = stoi(str.substr(6, 4));
	hh = stoi(str.substr(11, 2));
	mm = stoi(str.substr(14, 2));
	C[101].eDate(DD, MM, YYYY);
	C[101].Checkstartime(hh, mm);
	DD += n;
	if ((DD > 31 && (MM == 1 || MM == 3 || MM == 5 || MM == 7 || MM == 8 || MM == 10 || MM == 12)) || (DD > 30 && (MM == 4 || MM == 6 || MM == 9 || MM == 11)) || (DD > 29 && MM == 2 && ((YYYY % 4 == 0 && YYYY % 100 != 0) || (YYYY % 4 == 0 && YYYY % 100 != 0 && YYYY % 400 == 0))) || (DD > 28 && MM == 2 && !((YYYY % 4 == 0 && YYYY % 100 != 0) || (YYYY % 4 == 0 && YYYY % 100 != 0 && YYYY % 400 == 0)))) {
		DD = 0 + n;
		++MM;
	}
	if (MM > 12) {
		MM = 1;
		++YYYY;
	}
}

int comparetype(int &vet)
{
	if (comparedate2() != -1) {                              // if C[] have a date that match the user input date
		for (int i = comparedate2(); i < masterCnt; i++) {   // find the first object index that match type
			C[i].gettype(et);
			if (et == vet) {
				return i;
			}
		}
	}
	return -1;
}

void S2()   //4.2 function
{
	int tnum, savet, n, dd2, mm2, yyyy2, savehh, savemm, hhn, mn, ddn, mmn, yyyyn;
	eventValid = true;
	cout << "Please enter the type number that you want to search (N0. 1 to 4): ";
	cin >> tnum;
	cin.clear();
	cin.ignore();
	cout << "Want to show how many days? (1-7): ";
	cin >> n;
	cin.clear();
	cin.ignore();
	Today(DD, MM, YYYY, hh, mm, n);
	C[102].eDate(DD, MM, YYYY);   // save n day in C[102]
	C[102].Checkstartime(hh, mm);
	if (tnum > 0 && tnum < 5 && n > 0 && n < 8) {
		sort(C, C + masterCnt, compare);
		savet = comparetype(tnum);
		if (savet != -1) {
			cout << left << setw(25) << "Date and Time" << setw(45) << "Title" << setw(5) << "Type" << endl;
			for (int i = 0; i < masterCnt; i++) {
				C[savet + i].gettype(et);
				C[savet + i].getDate(dd2, mm2, yyyy2);
				C[savet + i].getStartime(savehh, savemm);
				C[102].getDate(ddn, mmn, yyyyn);
				C[102].getStartime(hhn, mn);
				if (yyyy2 < yyyyn || (yyyy2 == yyyyn && mm2 < mmn) || (yyyy2 == yyyyn && mm2 == mmn && dd2 < ddn) || (yyyy2 == yyyyn && mm2 == mmn && dd2 == ddn && savehh < hhn) || (yyyy2 == yyyyn && mm2 == mmn && dd2 == ddn && savehh == hhn && savemm <= mn)) {
					if (tnum == et) {
						C[savet + i].showTable();
					}
				}
			}
		} else {
			cout << "No type " << tnum << " event on the coming " << n << " days." << endl;
		}
	} else {
		cout << "Input value out of range." << endl;
	}
	C[101] = C[100];
	C[102] = C[100];
}

void sameDate(int index, int &Cnt)   //function for calendar (find how many events in one day)
{
	int dd1, mm1, yyyy1, dd2, mm2, yyyy2;
	for (int i = index + 1; i < masterCnt; ++i) {
		C[index].getDate(dd1, mm1, yyyy1);
		C[i].getDate(dd2, mm2, yyyy2);
		if (dd1 == dd2 && mm1 == mm2 && yyyy1 == yyyy2) {
			++Cnt;
		}
	}
}

int getDay(int date, int month, int year)   //function for calendar (calculate days per month)
{
	if (month == 1) {
		month = 13;
		year--;
	}
	if (month == 2) {
		month = 14;
		year--;
	}
	int a = date;
	int b = month;
	int c = year % 100;
	int d = year / 100;
	int e = a + 13 * (b + 1) / 5 + c + c / 4 + d / 4 + 5 * d;
	e = e % 7;
	if (e == 0)
		e = 7;
	return e;
}

int showCalender(int month, int year, int &index)   // Show calender
{
	int s3Cnt = 1, index2 = index, index3 = index, y = 0, iday = getDay(1, month, year), calender[6][7] = {{0}, {0}}, lday = 1, i, j, flag = 0, myv = 0;
	bool tooLong = false;
	DD = 0;
	cout << "\nCalendar Of Month : " << month << " / " << year << endl;
	cout << "\n ____________________________________________________________________________________________________________________________________________________________________________________________";
	cout << "\n|          Sunday          |           Monday         |          Tuesday         |         Wednesday        |         Thursday         |          Friday          |         Saturday         |";
	cout << "\n|__________________________|__________________________|__________________________|__________________________|__________________________|__________________________|__________________________|\n";
	int k, x, x2;
	for (i = 0; i <= 6; i++) {   // 6 row per month
		x = x2 = 3;
		for (k = 0; k <= x; k++) {       // internal row
			for (j = 1; j <= 7; j++) {   // week
				int l = 1;
				if (iday == 0 && i == 0 && j < 7 && k != 2) {
					cout << "|                          ";
				} else if (k == x) {   // close the box
					if (j == 7)
						cout << "|__________________________|";
					else
						cout << "|__________________________";
				} else if (j < iday && i == 0 && iday != 0) {
					cout << "|                          ";
				} else {
					if (calender[i][j - l] == 0)
						calender[i][j - l] = lday;
					if (k == 0) {
						if (flag == 1) {
							if (calender[i][j - l] % 10 == calender[i][j - l]) {
								if (j == 7)
									cout << "|                          |";
								else
									cout << "|                          ";
							} else {
								if (j == 7)
									cout << "|                          |";
								else
									cout << "|                          ";
							}
							lday++;
						} else {
							if (calender[i][j - l] % 10 == calender[i][j - l]) {
								if (j == 7 && flag != 1) {
									cout << "|";
									SetColor(240);   //white background black text
									cout << "            " << calender[i][j - l] << "             ";
									SetColor();   //back to original color (black background while text)
									cout << "|";
								} else if (flag != 1) {
									cout << "|";
									if (j == 1)
										SetColor(207);   //red background white text
									else
										SetColor(240);   //white background black text
									cout << "            " << calender[i][j - l] << "             ";
									SetColor();   //back to original color (black background while text)
								}
							} else {
								if (j == 7 && flag != 1) {
									cout << "|";
									SetColor(240);   //white background black text
									cout << "            " << calender[i][j - l] << "            ";
									SetColor();   //back to original color (black background while text)
									cout << "|";
								} else if (flag != 1) {
									cout << "|";
									if (j == 1)
										SetColor(207);   //red background white text
									else
										SetColor(240);   //white background black text
									cout << "            " << calender[i][j - l] << "            ";
									SetColor();   //back to original color (black background while text)
								}
							}
							lday++;
							if (flag == 0 && lday > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
								flag = 1;   // stop printing calendar no.
								myv = j;
							}
							if (flag == 0 && lday > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
								flag = 1;   // stop printing calendar no.
								myv = j;
							}
							if (flag == 0 && checkLeap(year) && lday > 29 && month == 2) {
								flag = 1;   // stop printing calendar no.
								myv = j;
							}
							if (flag == 0 && !checkLeap(year) && lday > 28 && month == 2) {
								flag = 1;   // stop printing calendar no.
								myv = j;
							}
						}
					} else if (k == 1) {
						if (j == 7)
							cout << "|                          |";
						else
							cout << "|                          ";
					} else if (k == 2) {
						sameDate(index, s3Cnt);   // count event in same day
						C[index].getDate(DD, MM, YYYY);
						if (calender[i][j - l] == DD && month == MM && year == YYYY) {   // check whether the event array equal to calender printing day
							if (s3Cnt > 0 && index == index3) {                          // make the height flexible
								x = x + s3Cnt;
							} else {
								x2 = x2 + s3Cnt;
								if (x2 > x)
									x = x2;
							}
							if (j == 7 && ((flag == 0) || (flag == 1 && myv >= j))) {
								(s3Cnt < 10) ? cout << "|         Total:" << s3Cnt << "          |" : cout << "|         Total:" << s3Cnt << "          |";
							} else if (j != 7 && ((flag == 0) || (flag == 1 && myv >= j)))
								(s3Cnt < 10) ? cout << "|         Total:" << s3Cnt << "          " : cout << "|         Total:" << s3Cnt << "         ";
							if (j == 7 && flag == 1 && myv < j) {
								cout << "|                          |";
							} else if (j != 7 && flag == 1 && myv < j)
								cout << "|                          ";
							index += s3Cnt;
							s3Cnt = 1;
						} else {
							s3Cnt = 1;
							if (j == 7 && ((flag == 0) || (flag == 1 && myv >= j))) {
								(s3Cnt < 10) ? cout << "|         Total:0          |" : cout << "|         Total:0         |";
							} else if (j != 7 && ((flag == 0) || (flag == 1 && myv >= j)))
								(s3Cnt < 10) ? cout << "|         Total:0          " : cout << "         Total:0         ";
							if (j == 7 && flag == 1 && myv < j) {
								cout << "|                          |";
							} else if (j != 7 && flag == 1 && myv < j)
								cout << "|                          ";
						}
					} else if (k == x) {
						if (j == 7) {
							cout << "|__________________________|";
						} else {
							cout << "|__________________________";
						}
					} else {
						C[index2].getDate(DD, MM, YYYY);
						if (calender[i][j - l] == DD && month == MM && year == YYYY) {
							sameDate(index2, s3Cnt);
							if (s3Cnt > 0 && (s3Cnt - y) > 0) {
								string str = C[index2 + y].getTitle();
								int len = str.length();
								if (len > 14 && tooLong == 0) {
									++x;
									if (j == 7) {
										tooLong = 1;
										cout << "|";
										SetColor(176);   //blue background black text
										C[index2 + y].calPrint();
										cout << left << setw(14) << str.substr(0, 14);
										SetColor();   //back to original color (black background while text)
										cout << "|";
									} else {
										tooLong = 1;
										cout << "|";
										SetColor(176);   //blue background black text
										C[index2 + y].calPrint();
										cout << left << setw(14) << str.substr(0, 14);
										SetColor();   //back to original color (black background while text)
									}
								} else if (len > 14 && tooLong == 1) {
									if (j == 7) {
										tooLong = 0;
										cout << "|";
										SetColor(176);   //blue background black text
										cout << left << setw(26) << str.substr(14, 26);
										SetColor();   //back to original color (black background while text)
										cout << "|";
									} else {
										tooLong = 0;
										cout << "|";
										SetColor(176);   //blue background black text
										cout << left << setw(26) << str.substr(14, 26);
										SetColor();   //back to original color (black background while text)
									}
								} else if (len <= 14 && tooLong == 0) {
									if (j == 7) {
										cout << "|";
										SetColor(176);   //blue background black text
										C[index2 + y].calPrint();
										cout << left << setw(14) << str.substr(0, 14);
										SetColor();   //back to original color (black background while text)
										cout << "|";
									} else {
										cout << "|";
										SetColor(176);   //blue background black text
										C[index2 + y].calPrint();
										cout << left << setw(14) << str.substr(0, 14);
										SetColor();   //back to original color (black background while text)
									}
								} else if (len <= 14 && tooLong == 1) {
									if (j == 7) {
										cout << "|";
										SetColor(176);   //blue background black text
										cout << "                          ";
										SetColor();   //back to original color (black background while text)
										cout << "|";
									} else {
										cout << "|";
										SetColor(176);   //blue background black text
										cout << "                          ";
										SetColor();   //back to original color (black background while text)
									}
								}
							} else {
								if (j == 7)
									cout << "|                          |";
								else
									cout << "|                          ";
							}
							index2 += s3Cnt;
							s3Cnt = 1;
						} else {
							if (j == 7)
								cout << "|                          |";
							else
								cout << "|                          ";
						}
					}
				}
			}
			if (tooLong == 0 && k > 2)
				++y;
			cout << "\n";
			index2 = index3;
		}
		index3 = index;
		y = 0;
		if (flag == 1)
			break;
	}
	return 0;
}

void S3()   //R4.3 function
{
	cin.ignore();
	int index = -1, month, year;
	string temD2;
	cout << "Please enter a month and year (MM-YYYY) or (MM YYYY): ";
	getline(cin, temD2);
	try {
		if (temD2.at(2) != ' ' && temD2.at(2) != '-')
			eventValid = false;
		month = stoi(temD2.substr(0, 2));
		year = stoi(temD2.substr(3, 4));
		DD = 1;
		C[101].eDate(DD, month, year);
	} catch (...) {
		eventValid = false;
	}
	if (eventValid == true) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			DD = 31;
		else if ((month == 2) && ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0)))) {
			DD = 29;
		} else if (month == 2) {
			DD = 28;
		} else
			DD = 30;
		C[102].eDate(DD, month, year);
		sort(C, C + masterCnt, compare);
		index = comparedate2();   // find the first day that match the user input
		showCalender(month, year, index);
	} else
		cout << "Error: Incorrect date format." << endl;
	C[101] = C[100];   // clear the input event object to 0
}

int main()
{
	string title, date, time;
	char prog_choice, choice;   //exit
	// do guide line said welcome message here?
	SetColor(143);
	cout << "Welcome to our program!" << endl;
	SetColor();
	do {
		SetColor(143);
		cout << "\n\n";
		SetColor();
		SetColor(143);
		cout << "*** Main Menu *** \n";
		SetColor();
		SetColor(143);
		cout << "[1] Add one event \n";
		SetColor();
		SetColor(143);
		cout << "[2] Delete one event \n";
		SetColor();
		SetColor(143);
		cout << "[3] Add events in batch \n";
		SetColor();
		SetColor(143);
		cout << "[4] Show events \n";
		SetColor();
		SetColor(143);
		cout << "[5] Credits \n";
		SetColor();
		SetColor(143);
		cout << "[6] Exit \n";
		SetColor();
		SetColor(143);
		cout << "***************** \n";
		SetColor();
		cout << "Option (1 - 6): ";
		cin >> prog_choice;
		cout << "\n\n";
		cin.ignore();
		switch (prog_choice) {
		case '1': {                                                           //R1
			int round1 = 0, round2 = 0, round3 = 0, round4 = 0, round5 = 0;   // loop times
			cout << "Enter the following information:" << endl
			     << endl;
			while (round1 < 3) {   // Loop more than 3 times and back to main// Loop more than 3 times and back to main
				eventValid = true;
				cout << "Event Title: ";
				getline(cin, title);
				cout << endl;
				C[masterCnt].Eventtitle(title);   // Call eventtitle function
				if (eventValid == false) {
					round1++;
					cout << "It can't more than 40 characters. Please try again!" << endl;
					cout << "You have " << 3 - round1 << " time to try." << endl
					     << endl;
				} else
					break;
			}

			//DD-MM-YYYY
			while (round1 < 3 && round2 < 3) {   // Loop more than 3 times and back to main
				eventValid = true;
				C[masterCnt].askDate(date, DD, MM, YYYY);   // Call askdate function
				if (eventValid == false) {
					round2++;
					cout << "Incorrect date format. Please try again!" << endl;
					cout << "You have " << 3 - round2 << " time to try." << endl
					     << endl;
				} else
					break;
			}

			//Event Start Time
			while (round1 < 3 && round2 < 3 && round3 < 3) {   // Loop more than 3 times and back to main
				eventValid = true;
				C[masterCnt].askSTime(time, hh, mm);   //Call asktime function
				if (eventValid == false) {
					round3++;
					cout << "Incorrect start time format. Please try again!" << endl;
					cout << "You have " << 3 - round3 << " time to try." << endl
					     << endl;
				} else
					break;
			}

			//Event End Time
			while (round1 < 3 && round2 < 3 && round3 < 3 && round4 < 3) {   // Loop more than 3 times and back to main
				eventValid = true;
				C[masterCnt].askETime(time, hh, mm);   // Call asktime function
				checktimeconflict2();
				if (eventValid == false) {
					round4++;
					cout << "Incorrect end time format. Please try again!" << endl;
					cout << "You have " << 3 - round4 << " time to try." << endl
					     << endl;
				} else
					break;
			}

			//Event type
			string strEt;
			while (round1 < 3 && round2 < 3 && round3 < 3 && round4 < 3 && round5 < 3) {   // Loop more than 3 times and back to main
				eventValid = true;
				cout << "Please input the event Type (1)Home, (2)Work, (3)Study, (4)Play: ";   // Value should be between 1 and 4;
				getline(cin, strEt);
				try {
					et = stoi(strEt.substr(0, 1));
					C[masterCnt].etype(et);
				} catch (...) {
					eventValid = false;
				}
				if (eventValid == false) {
					round5++;
					cout << endl
					     << "Incorrect event type. Please try again!" << endl;
					cout << "You have " << 3 - round5 << " time to try." << endl
					     << endl;
				} else
					break;
			}

			// Check timeconflict
			if (masterCnt > 0) {
				checktimeconflict();   // Call checktimeconflict function
			}
			if (eventValid == false && round1 < 3 && round2 < 3 && round3 < 3 && round4 < 3 && round5 < 3) {   // create event failure when timeconflict appeared
				cout << endl
				     << "Event create failed. There is a time conflict in the event. \n"
				     << endl;
			}

			if (eventValid == true) {   // Creat event when all the checking are valid
				cout << endl
				     << "Event successfully created. ";
				++masterCnt;
			}
			break;
		}

		case '2': {   //R2
			int savec, dd2, mm2, yyyy2, round = 0, userinput, countevent = 0;
			while (round < 3) {   //situation of invalid input
				eventValid = true;
				C[masterCnt].askDate(date, dd2, mm2, yyyy2);
				if (eventValid == false) {
					round++;
					cout << "Incorrect end time format. Please try again!" << endl;
					cout << "You have " << 3 - round << " time to try." << endl;
				} else {
					sort(C, C + masterCnt, compare);
					savec = comparedate(dd2, mm2, yyyy2);
					if (savec == -1) {
						cout << "This day has no event.";
					} else {
						cout << left << setw(7) << "Index" << setw(25) << "Date and Time" << setw(45) << "Title"
						     << "Type" << endl;
						for (int i = savec + 1; i < masterCnt; ++i) {   //count how many events
							C[savec].getDate(DD, MM, YYYY);
							if (DD == dd2 && MM == mm2 && YYYY == yyyy2)
								countevent++;
						}
						for (int i = 0; i <= countevent; i++) {   //display events in that day
							C[savec + i].getDate(DD, MM, YYYY);
							if (DD == dd2 && MM == mm2 && YYYY == yyyy2) {
								cout << setw(7) << i + 1;   //show the index number
								C[savec + i].showTable();
							}
						}
						countevent++;
						cout << endl;
						cout << "Please input the index number for deleting the event: ";
						cin >> userinput;
						if (userinput <= countevent && userinput > 0) {
							int position = savec + userinput - 1;
							for (int i = position; i < masterCnt; i++)   //Deleting the event
							{
								C[i] = C[i + 1];
							}
							--masterCnt;
							cout << endl
							     << "Event deleted successfully.";
						} else {
							cout << endl
							     << "Wrong index number.";
						}
					}
					break;
				}
			}
			break;
		}

		case '3': {   //R3
			string input;
			int failCnt = 0,
			    r2Cnt = 0;
			// keep asking user to input
			while (getline(cin, input)) {
				if (input != "0") {
					splitStr(input, title, DD, MM, YYYY, hh, mm, et);
					C[masterCnt].Eventtitle(title);
					C[masterCnt].eDate(DD, MM, YYYY);
					C[masterCnt].etype(et);
					checktimeconflict2();
					if (masterCnt > 0)
						checktimeconflict();
					if (eventValid == true) {
						++masterCnt;
						++r2Cnt;
					} else {
						++failCnt;
						eventValid = true;
					}
				} else
					break;
			}
			cout << "\nTotal " << r2Cnt + failCnt << " events in batch\n"
			     << r2Cnt << " event(s) added\n"
			     << failCnt << " event(s) not added due to time conflict" << endl;
			break;
		}

		case '4': {   //R4
			char opt_choice;
			do {
				SetColor(143);
				cout << "\n\n";
				SetColor();
				SetColor(143);
				cout << "***** Show Event Menu *****" << endl;
				SetColor();
				SetColor(143);
				cout << "[1] Show all events" << endl;
				SetColor();
				SetColor(143);
				cout << "[2] Show events (list view)" << endl;
				SetColor();
				SetColor(143);
				cout << "[3] Show events (calendar view)" << endl;
				SetColor();
				SetColor(143);
				cout << "[4] Return to Main Menu" << endl;
				SetColor();
				SetColor(143);
				cout << "***************************" << endl;
				SetColor();
				cout << "Option (1 - 4): ";
				cin >> opt_choice;
				cout << "\n\n";
				switch (opt_choice) {
				case '1':
					S1();
					break;
				case '2':
					S2();
					break;
				case '3':
					S3();
					break;
				case '4':
					break;
				default:
					cout << "No such option " << opt_choice << endl;
					break;
				}
			} while (opt_choice != '4');
		} break;

		case '5':   //Credits
			cout << left << setw(16) << "Student Name" << setw(12) << "Student ID"
			     << "Class\n"
			     << setw(16) << "CHEUNG Tsz Lai" << setw(12) << "19013740A"
			     << "201D\n"
			     << setw(16) << "LAU Chi Leung" << setw(12) << "19011757A"
			     << "201D\n"
			     << setw(16) << "CHENG Wai Ying" << setw(12) << "19006121A"
			     << "201D\n"
			     << setw(16) << "PUN Wing Hon" << setw(12) << "19187413A"
			     << "201D\n"
			     << setw(16) << "WONG Cheuk Him" << setw(12) << "18062182A"
			     << "201C\n"
			     << setw(16) << "KWOK Kam Yau" << setw(12) << "19010110A"
			     << "201D\n";
			break;

		case '6':   //Exit
			do {
				cout << "Please confirm again (Y/N): ";
				cin >> choice;
				if (choice == 'y' || choice == 'Y')
					break;
				else if (choice == 'n' || choice == 'N')
					break;
				cout << "No such choice. \n"
				     << endl;
			} while (choice != 'y');
			break;
		default:
			cout << "No such option " << prog_choice << endl;
			break;
		}
	} while ((prog_choice != '6') || (choice != 'y' && choice != 'Y'));
	cout << "Program terminates. Thanks for using our program!" << endl;
	return 0;
}
//END