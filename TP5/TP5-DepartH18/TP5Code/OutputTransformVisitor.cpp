#include "OutputTransformVisitor.h"
#include "Objet3DPart.h"
#include "Objet3DComposite.h"

void OutputTransformVisitor::visit(Objet3DPart & obj)
{
	// Imprimer tous les triangles contenus dans l'objet
	// Meme methode que OutputVisitor::visit(Objet3DPart& obj)
	unsigned int indice = 0;
	TriangleIterator it = obj.triangle_begin();
	while (it != obj.triangle_end()) {
		m_stream << m_indent
			<< "T" << indice++ << ":"
			<< "(" << it->s1() << ")" << "|"
			<< "(" << it->s2() << ")" << "|"
			<< "(" << it->s3() << ")" << std::endl;
		it++;
	}
}

void OutputTransformVisitor::visit(Objet3DComposite & obj)
{
	// Si l'objet composite a des enfants, faire:
	//     - Incrementer l'indentation de 3 espaces
	//     - Imprimer "COMPOSITE:" selon la bonne indentation sur une ligne seule
	//     - Invoquer la methode TransformVisitor::visit(Objet3DComposite &) de 
	//       la classe de base  pour visiter les enfants
	//     - Restaurer l'indentation
	if (obj.begin() != obj.end()) {
		m_indent += "   ";
		m_stream << m_indent
			<< "COMPOSITE:" << std::endl;
		TransformVisitor::visit(obj);
		m_indent = m_indent.substr(3, m_indent.size());
	}
}
