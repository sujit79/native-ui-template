#ifndef UI_GENERATE_H_
#define UI_GENERATE_H_

#include "../../include/common.h"
#include "../lang/Draw.h"

namespace xuigenerate {

	class UI_Generate: public xmlpp::SaxParser
	{
		private:
			std::vector<Draw*> draw_list;
			std::string node_title;
			int node_x_coord, node_y_coord;
			std::vector<std::string> item_list;
		public:
			UI_Generate();
			virtual ~UI_Generate();
			Draw* find(std::string title);
			void construct(const Glib::ustring& node_name,const AttributeList& attr);
			void setAttributes(xmlpp::SaxParser::AttributeList::const_iterator iter);
	};

}; // End Namespace

#endif /* UI_GENERATE_H_ */
