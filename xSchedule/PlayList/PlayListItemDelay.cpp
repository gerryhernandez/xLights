#include "PlayListItemDelay.h"
#include <wx/xml/xml.h>
#include <wx/notebook.h>
#include "PlayListItemDelayPanel.h"

PlayListItemDelay::PlayListItemDelay(wxXmlNode* node) : PlayListItem(node)
{
    PlayListItemDelay::Load(node);
}

void PlayListItemDelay::Load(wxXmlNode* node) 
{
    PlayListItem::Load(node);
    _duration = wxAtoi(node->GetAttribute("Duration", "50"));
}

PlayListItemDelay::PlayListItemDelay() : PlayListItem()
{
    _duration = 50;
    SetName("All Off");
}

wxXmlNode* PlayListItemDelay::Save()
{
    wxXmlNode * node = new wxXmlNode(nullptr, wxXML_ELEMENT_NODE, "PLIDelay");

    node->AddAttribute("Duration", wxString::Format(wxT("%i"), _duration));

    PlayListItem::Save(node);

    return node;
}

void PlayListItemDelay::Configure(wxNotebook* notebook)
{
    notebook->AddPage(new PlayListItemDelayPanel(notebook, this), "Delay", true);
}
