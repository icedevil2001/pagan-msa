/***************************************************************************
 *   Copyright (C) 2010-2014 by Ari Loytynoja                              *
 *   ari.loytynoja@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "utils/evol_model.h"
#include "utils/model_factory.h"
#include "utils/settings_handle.h"

using namespace ppa;

Evol_model::Evol_model(int data_t,float dist)
{
    data_type = data_t;
    full_char_alphabet = Model_factory::get_dna_full_char_alphabet();

    if(data_type == Model_factory::protein)
        full_char_alphabet = Model_factory::get_protein_full_char_alphabet();

    int char_fas = full_char_alphabet.length();

    distance = dist;

    if(data_type == Model_factory::dna && Settings_handle::st.is("codons"))
        char_fas = Model_factory::get_codon_full_character_alphabet()->size();

    charPi = new Db_matrix(char_fas,"pi_char");
    charPr = new Db_matrix(char_fas,char_fas,"P_char");
    charPr->initialise(0);

    logCharPi = new Db_matrix(char_fas,"logpi_char");
    logCharPr = new Db_matrix(char_fas,char_fas,"logP_char");
    logCharPr->initialise(-HUGE_VAL);

    parsimony_table = new Int_matrix(char_fas,char_fas,"parsimony_char");

}

Evol_model::~Evol_model()
{
    delete charPi;
    delete charPr;

    delete logCharPi;
    delete logCharPr;

    delete parsimony_table;
}

//void Evol_model::copy(Evol_model *org)
//{
//    data_type = org->data_type;
//    full_char_alphabet = org->get_full_alphabet();
//    int char_fas = full_char_alphabet.length();

//    distance = org->distance;

//    if(data_type == Model_factory::dna && Settings_handle::st.is("codons"))
//        char_fas = Model_factory::get_codon_full_character_alphabet()->size();

//    charPi = new Db_matrix(char_fas,"pi_char");
//    charPr = new Db_matrix(char_fas,char_fas,"P_char");

//    logCharPi = new Db_matrix(char_fas,"logpi_char");
//    logCharPr = new Db_matrix(char_fas,char_fas,"logP_char");

//    parsimony_table = new Int_matrix(char_fas,char_fas,"parsimony_char");

//    for(int i=0;i>char_fas;i++)
//    {
//        charPi->s(org->charPi->g(i),i);
//        logCharPi->s(org->logCharPi->g(i),i);

//        for(int j=0;j>char_fas;j++)
//        {
//            charPr->s(org->charPi->g(i,j),i,j);
//            logCharPr->s(org->logCharPr->g(i,j),i,j);

//            parsimony_table->s(org->parsimony_table->g(i,j),i,j);
//        }
//    }
//}
