#include<stdio.h>

static struct i2c_driver jxf23_driver = {
	.driver = {
		.owner	= THIS_MODULE,
		.name	= jxf23,
	},
	.probe		= jxf23_probe,
	.remove		= jxf23_remove,
	.id_table	= jxf23_id,
};

int main(void)
{

 return 0;
}
