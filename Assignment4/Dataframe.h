#ifndef DATAFRAME_H
#define DATAFRAME_H
#include <array>

class Dataframe{
    public:
	using dataframe_t = std::array<std::uint8_t, 255>;
        Dataframe();
	void setData(const dataframe_t &data, std::uint8_t size);
	void setChecksum();
	void setDataframe(const dataframe_t &dataframe);
	dataframe_t getDataframe() const;
	void show() const;
	void showAll() const;
	bool checksumIsCorrect() const;
	void clear();
    private:
	dataframe_t frame;
	int dataSize = 255;
};

#endif
