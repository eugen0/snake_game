#include "../InfoBox.h"

void InfoBox::SetInfo(std::string msg) {msg_.emplace_back(msg);};
std::vector<std::string>& InfoBox::GetInfo() {return msg_;}
//InfoBox::InfoBox(std::string msg) {
 //   msg_.emplace_back(msg);
//}

void InfoBox::ClearInfo() {msg_.clear();}

InfoBox::InfoBox() {};

