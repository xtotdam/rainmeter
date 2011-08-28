/*
  Copyright (C) 2011 Birunthan Mohanathas

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef _DIALOGMANAGE_H_
#define _DIALOGMANAGE_H_

#include "MeterWindow.h"
#include "Rainmeter.h"
#include "TrayWindow.h"
#include "Dialog.h"

class CDialogManage : public CDialog
{
public:
	CDialogManage(HWND window);
	virtual ~CDialogManage();

	static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	INT_PTR OnInitDialog(WPARAM wParam, LPARAM lParam);
	INT_PTR OnNotify(WPARAM wParam, LPARAM lParam);
	INT_PTR OnCommand(WPARAM wParam, LPARAM lParam);

	static void Open(int tab = 0);
	static void OpenSkin(CMeterWindow* meterWindow);

	static void UpdateSkins(CMeterWindow* meterWindow, bool deleted = false);
	static void UpdateThemes();

	static WINDOWPLACEMENT c_WindowPlacement;
	static CDialogManage* c_Dialog;

private:
	// Skins tab
	class CTabSkins : public CTab
	{
	public:
		CTabSkins(HWND window);

		virtual void Initialize();

		static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		INT_PTR OnNotify(WPARAM wParam, LPARAM lParam);
		INT_PTR OnCommand(WPARAM wParam, LPARAM lParam);

		void Update(CMeterWindow* meterWindow, bool deleted);

		static void SelectTreeItem(HWND tree, HTREEITEM item, LPCWSTR name);

	private:
		void SetControls();
		void DisableControls(bool clear = false);
		void ReadSkin();

		static void PopulateTree(HWND tree, TV_INSERTSTRUCT& tvi, const std::vector<CRainmeter::CONFIGMENU>& configMenuData);

		std::wstring m_FileName;
		std::wstring m_SkinName;
		CMeterWindow* m_SkinWindow;
		bool m_HandleCommands;
		bool m_IgnoreUpdate;
	};

	// Themes tab
	class CTabThemes : public CTab
	{
	public:
		CTabThemes(HWND window);

		virtual void Initialize();

		static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		INT_PTR OnNotify(WPARAM wParam, LPARAM lParam);
		INT_PTR OnCommand(WPARAM wParam, LPARAM lParam);

		void Update();

	private:
		bool m_LoadTheme;
	};
	
	// Settings tab
	class CTabSettings : public CTab
	{
	public:
		CTabSettings(HWND window);

		virtual void Initialize();

		static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		INT_PTR OnCommand(WPARAM wParam, LPARAM lParam);
	};

	CTabSkins* m_TabSkins;
	CTabThemes* m_TabThemes;
	CTabSettings* m_TabSettings;
};

#endif

