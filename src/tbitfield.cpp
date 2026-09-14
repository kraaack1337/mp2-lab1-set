// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООПфференцированный зачет 
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include <stdexcept>

TBitField::TBitField(int len) 
{
    if (len < 0){
        throw std::out_of_range("Dlina ne mojet bit' <0");
    }
    if (len == 0){
        MemLen = BitLen = 0;
        pMem = nullptr;
        return;
    }
    
    BitLen = len;
    MemLen = (len + (sizeof(TELEM) * 8) - 1) / (sizeof(TELEM) * 8);
    pMem = new TELEM[MemLen]();
        
    
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{   
    if (bf.MemLen == 0){
        MemLen = BitLen = 0;
        pMem = nullptr;
    }
    else{

        BitLen = bf . BitLen; 
        MemLen = bf . MemLen;

        pMem  = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++) {pMem[i] = bf.pMem[i];}
    }
}

TBitField::~TBitField()
{
    delete [] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{   
    if (n < 0 || n >= BitLen){
        throw std::out_of_range("Index slishkom bol'shoi or <0, try another one:)");
    }
    return (n/(sizeof(TELEM) * 8));
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n < 0 || n >= BitLen){
        throw std::out_of_range("Index slishkom bol'shoi or <0, try another one:)");
    }

    unsigned int position_in_mem = n % (sizeof(TELEM) * 8);
    TELEM mask = TELEM(1) << position_in_mem;
    return mask;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return 0;
}

void TBitField::SetBit(const int n) // установить бит
{
}

void TBitField::ClrBit(const int n) // очистить бит
{
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    return TBitField(0);
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    return TBitField(0);
}

TBitField TBitField::operator~(void) // отрицание
{
    return TBitField(0);
}

// ввод/вывод

std::istream &operator>>(std::istream &istr, TBitField &bf) // ввод
{
    return istr;
}

std::ostream &operator<<(std::ostream &ostr, const TBitField &bf) // вывод
{
    return ostr;
}
