class Pierbox: Exile_AbstractCraftingRecipe
{
	name = "Pier Box";
	pictureItem = "Land_Pier_Box_F_Kit";
	returnedItems[] = 
	{
		{1, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"},
		{1, "Land_Pier_Box_F_Kit"}
	};
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{4, "Exile_Item_Cement"},
		{4, "Exile_Item_Sand"},
		{5, "Exile_Item_WoodPlank"},
		{1, "Exile_Item_FuelCanisterFull"},
		{1, "Exile_Item_WaterCanisterDirtyWater"}
	};
	tools[] =
	{
		"Exile_Item_Shovel",
	};
	requiresConcreteMixer = 1;
	category = "COG Buildables";
};

class Veh_Ammo_Crate: Exile_AbstractCraftingRecipe
{
	name = "Vehicle Ammo Crate";
	pictureItem = "Box_NATO_AmmoVeh_F_Kit";
	returnedItems[] = 
	{
		{1, "Box_NATO_AmmoVeh_F_Kit"}
	};
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{4, "Exile_Item_MetalBoard"},
		{3, "Exile_Item_MetalScrews"},
		{3, "Exile_Item_JunkMetal"},
		{3, "3Rnd_HE_Grenade_shell"},
		{3, "150Rnd_762x54_Box"}
	};
	tools[] =
	{
		"Exile_Item_Screwdriver",
		"Exile_Item_Grinder",
		"Exile_Item_Hammer"
	};
	category = "COG Buildables";
};