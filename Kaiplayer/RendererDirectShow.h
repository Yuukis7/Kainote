//  Copyright (c) 2020, Marcin Drob

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

#pragma once

#include "RendererVideo.h"

struct CUSTOMVERTEX
{
	D3DXVECTOR3 position; // The position
	FLOAT       tu, tv;   // The texture coordinates
};
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_TEX1)

class RendererDirectShow : public RendererVideo
{
	friend class RendererVideo;
	friend class VideoCtrl;
public:
	RendererDirectShow(VideoCtrl *control);
	virtual ~RendererDirectShow();

	bool OpenFile(const wxString &fname, int subsFlag, bool vobsub, bool changeAudio = true);
	bool OpenSubs(int flag, bool redraw = true, wxString *text = NULL, bool resetParameters = false);
	bool Play(int end = -1);
	bool Pause();
	bool Stop();
	void SetPosition(int _time, bool starttime = true, bool corect = true, bool async = true);
	int GetFrameTime(bool start = true);
	void GetStartEndDelay(int startTime, int endTime, int *retStart, int *retEnd);
	int GetFrameTimeFromTime(int time, bool start = true);
	int GetFrameTimeFromFrame(int frame, bool start = true);
	int GetPlayEndTime(int time);
	int GetDuration();
	int GetVolume();
	void GetVideoSize(int *width, int *height);
	void GetFpsnRatio(float *fps, long *arx, long *ary);
	void SetVolume(int vol);
	bool DrawTexture(byte *nframe = NULL, bool copy = false);
	void Render(bool RecreateFrame = true, bool wait = true);
	void RecreateSurface();
	void EnableStream(long index);
	void ChangePositionByFrame(int cpos);
	void ChangeVobsub(bool vobsub = false);
	wxArrayString GetStreams();
	byte *GetFramewithSubs(bool subs, bool *del);
	
	bool EnumFilters(Menu *menu);
	bool FilterConfig(wxString name, int idx, wxPoint pos);
	bool InitRendererDX();
	void OpenKeyframes(const wxString &filename);
	void ClearObject();
private:
	DShowPlayer *m_DirectShowPlayer;
	LPDIRECT3DTEXTURE9 m_SubtitlesTexture = NULL;
	LPDIRECT3DTEXTURE9 m_BlitTexture = NULL;
	unsigned char * m_SubtitlesBuffer = NULL;
	CUSTOMVERTEX m_Vertices[4];
	int m_WindowWidth = -1;
	int m_WindowHeight = -1;
	int m_LastBufferSize = -1;
};