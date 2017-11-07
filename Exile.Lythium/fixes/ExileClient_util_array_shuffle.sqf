/**
 * ExileClient_util_array_shuffle
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
 * infiSTAR Improved Network Security - The original function was not shuffling
 *
 */

_in = _this;
_out = [];
_count = count _in;
for "_i" from 1 to _count do 
{
	_r = selectRandom _in;
	_out pushBackUnique _r;
	_in = _in - [_r];
};
_out