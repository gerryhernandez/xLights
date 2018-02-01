#ifndef XLCOLORPICKERFIELDS_H
#define XLCOLORPICKERFIELDS_H

//(*Headers(xlColorPickerFields)
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/gbsizer.h>
//*)

#include "xlColorPicker.h"
#include "Color.h"
#include "xlColorCanvas.h"
#include "xlSlider.h"

wxDECLARE_EVENT(EVT_PAINT_COLOR, wxCommandEvent);

class xlColorPickerFields: public xlColorPicker
{
	public:

		xlColorPickerFields(wxWindow* parent, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, long style=wxTAB_TRAVERSAL, const wxString& name="Any");
		virtual ~xlColorPickerFields();

        virtual void SetColor(xlColor& color );
        virtual void NotifyColorChange();

		//(*Declarations(xlColorPickerFields)
		wxBitmapButton* BitmapButton_Swatch8;
		wxTextCtrl* TextCtrl_Blue;
		wxRadioButton* RadioButton_Red;
		wxBitmapButton* BitmapButton_Swatch2;
		wxTextCtrl* TextCtrl_Hue;
		wxBitmapButton* BitmapButton_Swatch3;
		xlSlider* SliderRight;
		xlSlider* SliderLeft;
		wxGridBagSizer* GridBagSizer1;
		wxRadioButton* RadioButton_SwatchMarker;
		wxBitmapButton* BitmapButton_Swatch4;
		wxTextCtrl* TextCtrl_Green;
		xlColorCanvas* Panel_Slider;
		wxBitmapButton* BitmapButton_Swatch7;
		wxTextCtrl* TextCtrl_Brightness;
		wxTextCtrl* TextCtrl_Saturation;
		wxRadioButton* RadioButton_Saturation;
		wxPanel* Panel_CurrentColor;
		wxRadioButton* RadioButton_Green;
		wxRadioButton* RadioButton_Brightness;
		xlColorCanvas* Panel_Palette;
		wxBitmapButton* BitmapButton_Swatch6;
		wxRadioButton* RadioButton_Blue;
		wxBitmapButton* BitmapButton_Swatch1;
		wxBitmapButton* BitmapButton_Swatch5;
		wxRadioButton* RadioButton_Hue;
		wxTextCtrl* TextCtrl_Red;
		//*)

	protected:

		//(*Identifiers(xlColorPickerFields)
		static const long ID_PANEL_Palette;
		static const long ID_PANEL_SLIDER;
		static const long ID_BITMAPBUTTON_Swatch1;
		static const long ID_SLIDER_Left;
		static const long ID_SLIDER_Right;
		static const long ID_PANEL_CurrentColor;
		static const long ID_RADIOBUTTON_Hue;
		static const long ID_RADIOBUTTON_Saturation;
		static const long ID_RADIOBUTTON_Brightness;
		static const long ID_RADIOBUTTON_Red;
		static const long ID_RADIOBUTTON_Green;
		static const long ID_RADIOBUTTON_Blue;
		static const long ID_TEXTCTRL_Hue;
		static const long ID_TEXTCTRL_Saturation;
		static const long ID_TEXTCTRL_BrightnessCPF;
		static const long ID_TEXTCTRL_Red;
		static const long ID_TEXTCTRL_Green;
		static const long ID_TEXTCTRL_Blue;
		static const long ID_BITMAPBUTTON_Swatch2;
		static const long ID_BITMAPBUTTON_Swatch3;
		static const long ID_BITMAPBUTTON_Swatch4;
		static const long ID_BITMAPBUTTON_Swatch5;
		static const long ID_BITMAPBUTTON_Swatch6;
		static const long ID_BITMAPBUTTON_Swatch7;
		static const long ID_BITMAPBUTTON_Swatch8;
		static const long ID_RADIOBUTTON_SwatchMarker;
		//*)

	private:

		//(*Handlers(xlColorPickerFields)
		void OnSliderLeftCmdSliderUpdated(wxScrollEvent& event);
		void OnSliderRightCmdSliderUpdated(wxScrollEvent& event);
		void OnRadioButton_ModeSelect(wxCommandEvent& event);
		void OnTextCtrl_Text(wxCommandEvent& event);
		void OnBitmapButton_SwatchClick(wxCommandEvent& event);
		//*)

        void ProcessSliderColorChange(wxCommandEvent& event);
        void ProcessPaletteColorChange(wxCommandEvent& event);
        int GetSliderPos();
        void SetColorFromSliderPos(int position);
        void UpdateTextFields();
        int RangeLimit( wxTextCtrl* text_ctrl, int lower_limit, int upper_limit );

        ColorDisplayMode mDisplayMode;
        wxBitmapButton* mActiveButton;
        wxWindow* mMsgParent;

		DECLARE_EVENT_TABLE()
};

#endif
