
#include "unity.h"
#include <string.h>
#include "ntxfr.h"

void test_ntxfr_is_valid(void) {
	uint8_t rawData[] = {0x01, 0x08, 0x02, 0x20, 0x21, 0x22, 0x1d, 0xd4 };
	ntxfr_data_t data= {rawData, sizeof(rawData)};

	TEST_ASSERT_TRUE(ntxfr_is_valid(data));
	rawData[0] = 0xff;
	TEST_ASSERT_FALSE(ntxfr_is_valid(data));
	rawData[0] = 0x01;
	data.len = 4;
	TEST_ASSERT_FALSE(ntxfr_is_valid(data));
}

#if defined(ESP_PLATFORM)
TEST_CASE("NTXFR is valid", "[Netronix frame]")
{
	test_ntxfr_is_valid();
}
#endif
