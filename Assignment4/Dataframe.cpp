#include <iostream>
#include "Dataframe.h"

Dataframe::Dataframe()
{
  frame.fill(0);
}

void Dataframe::setData(const Dataframe::dataframe_t &data, std::uint8_t size)
{
  dataSize = size;
  frame[0] = 19;
  frame[1] = dataSize;
  for (int i=0; i<dataSize; i++)
  {
    frame[i+2] = data[i];
  }
  setChecksum();
}

void Dataframe::setChecksum()
{
  uint8_t sum{0};
  for (int i=0; i<(dataSize+2); i++)
  {
    sum += frame[i];
  }
  frame[dataSize+2] = 256 - (sum % 256);
}

void Dataframe::setDataframe(const Dataframe::dataframe_t &dataframe)
{
  frame.fill(0);
  unsigned int index{0};
  for (auto i:dataframe)
  {
    frame[index] = i;
    index++;
  }
}

Dataframe::dataframe_t Dataframe::getDataframe() const
{
  return frame;
}

void Dataframe::show() const
{
  std::cout<<"The data frame is: ";
  for (int i=0; i<(dataSize+2); i++)
    std::cout<<"["<<static_cast<int>(frame[i])<<"] ";
  std::cout<<"\n";
}

void Dataframe::showAll() const
{
  std::cout<<"The data frame is: ";
  for (auto i:frame)
    std::cout<<"["<<static_cast<int>(i)<<"] ";
  std::cout<<"\n";
}

bool Dataframe::checksumIsCorrect() const
{
  uint8_t sum{0};
  for (auto i:frame)
    sum += i;
  if (sum == 0x00)
    return true;
  return false;
}

void Dataframe::clear()
{
  frame.fill(0);
}