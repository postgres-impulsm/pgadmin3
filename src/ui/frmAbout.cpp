//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// Copyright (C) 2002, The pgAdmin Development Team
// This software is released under the pgAdmin Public Licence
//
// frmAbout.cpp - About Box
//
//////////////////////////////////////////////////////////////////////////

// wxWindows headers
#include <wx/wx.h>
#include <wx/image.h>

// App headers
#include "pgAdmin3.h"
#include "frmAbout.h"

// Icons
#include "images/pgAdmin3.xpm"

// Splash
#include "images/splash.xpm"

BEGIN_EVENT_TABLE(frmAbout, wxDialog)
EVT_PAINT(frmAbout::OnPaint)
END_EVENT_TABLE()

frmAbout::frmAbout(wxFrame *parent)
: wxDialog(parent, -1, APPNAME_L, wxDefaultPosition, wxDefaultSize, wxCAPTION | wxDIALOG_MODAL | wxSYSTEM_MENU | wxSTAY_ON_TOP)
{

    wxLogInfo(wxT("Creating an about box"));

    // Icon
    SetIcon(wxIcon(pgAdmin3_xpm));

    // Image
    about = wxBitmap(splash_xpm);

    SetClientSize(about.GetWidth(), about.GetHeight());
    wxString version = wxT(" "VERSION" ("__DATE__") ");

    // Creating a 0 size panel is the only way to position the static text on unix. If you know a better way..!
	(void)new wxPanel(this, -1, wxPoint(7,95), wxSize(0,0));
	(void)new wxStaticText(this, -1, version, wxPoint(7,95));
	this->Center();
}

frmAbout::~frmAbout()
{
    wxLogInfo(wxT("Destroying an about box"));
}

void frmAbout::OnPaint(wxPaintEvent& WXUNUSED(event))
{
	wxPaintDC dc(this);
	dc.DrawBitmap(about, 0, 0);
	
}
