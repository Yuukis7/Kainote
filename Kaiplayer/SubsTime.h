//  Copyright (c) 2016, Marcin Drob

//  Kainote is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  Kainote is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with Kainote.  If not, see <http://www.gnu.org/licenses/>.

#ifndef TIMECONV_H_INCLUDED
#define TIMECONV_H_INCLUDED
#include <wx/string.h>
#include <wx/thread.h>


class STime
{
private:

    char form;
    
public:
	int orgframe;
	//wxString raw;
	int mstime;

	STime();
	STime(int ms);
	~STime();
	void SetRaw(wxString rawtime, char format);
	void NewTime(int ms);
	void ParseMS(wxString time);
	wxString raw(char format=0);//, float fps=0
	char GetFormat();
	void ChangeFormat(char format,float fps=0);
	wxString GetFormatted(char format);
	void Change(int ms);
	bool operator> (STime por);
	bool operator< (STime por);
	bool operator>= (STime por);
	bool operator<= (STime por);
	bool operator== (STime por);
	STime operator- (STime por);
};







#endif // TIMECONV_H_INCLUDED
