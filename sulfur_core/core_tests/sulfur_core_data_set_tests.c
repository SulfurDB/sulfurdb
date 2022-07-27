#include "unit_test_tools.h"
#include "sulfur_data_set.h"


static void test_sulfur_dataset_init(void)
{
	sulfur_dataset_t set;
	double values[] = {4.0, 4.0, 5.5, 3.0, 2.2, 2.1};
	sulfur_dataset_init(&set, values, sizeof(values), 2, 2);
	UNIT_CHECK(set.data != NULL);
	UNIT_CHECK(set.size = sizeof(values));
	UNIT_CHECK(set.dimensions = 2);
	UNIT_CHECK(set.precision = 2);
	sulfur_dataset_deinit(&set);
	UNIT_CHECK(set.data == NULL);
}



int main(int argc, char const *argv[])
{
	test_sulfur_dataset_init();
	return _failure_result();
}