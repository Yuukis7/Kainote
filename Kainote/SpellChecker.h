// Copyright (c) 2006, 2007, Niels Martin Hansen
// Copyright (c) 2016 - 2020, Marcin Drob
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of the Aegisub Group nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Aegisub Project http://www.aegisub.org/

#pragma once

#include "Config.h"
#include <hunspell.hxx>
#include <wx/string.h>
#include "LineParse.h"

class SpellChecker
{
public:

	SpellChecker();
	~SpellChecker();
	bool Initialize();
	static void AvailableDics(wxArrayString &dics, wxArrayString &symbols);
	void Cleaning();
	//converts Arabic words to basic chars
	//to use with spellchecker
	bool CheckWord(wxString *word);
	bool AddWord(const wxString &word);
	bool RemoveWords(const wxArrayString &word);
	void Suggestions(wxString word, wxArrayString &results);

	//text for both
	//errors table for both
	//misspells table for MyTextEditor
	//tags replacement for SubsGrid
	void CheckTextAndBrackets(const wxString &text, TextData *errs, bool spellchecker, int subsFormat, std::vector<MisspellData> *misspells = nullptr, int replaceTagsLen = -1);
	//for spellchecker window
	void CheckText(const wxString &text, std::vector<MisspellData> *errs, int subsFormat);
	bool FindMisspells(const wxString &text, const wxString &textToFind, std::vector<MisspellData> *misspells, int subsFormat);
	void ReplaceMisspell(const wxString &misspell, const wxString &misspellReplace, int start, int end, wxString *textToReplace, int *newPosition);
	static SpellChecker *Get();
	static void Destroy();

private:
	Hunspell *hunspell;
	wxCSConv *conv;
	static SpellChecker *SC;
	wxString dictionaryPath;
	wxString userDictionaryPath;
	bool useSpellChecker = true;
	bool isRTL = false;
	//no const cause of clearing
	inline void Check(std::wstring &checkText, TextData *errs, std::vector<MisspellData> *misspells, std::vector<size_t> &textOffset, const wxString &text, bool repltags, int replaceTagsLen);
};


