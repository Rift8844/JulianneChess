#include "../Bitboard.hpp"
#include <array>

#pragma once

typedef std::array<std::array<Bitboard, 8>, 8> MoveTable;

//I generated the magics myself... not to brag but I'm a bit of a magician :>

namespace Pieces::MoveTables {

	MoveTable constexpr King {{
		{ 0x000000000000c0c0, 0x0000000000c0c0c0, 0x00000000c0c0c000, 0x000000c0c0c00000, 0x0000c0c0c0000000, 0x00c0c0c000000000, 0x00c0c00000000000, 0x00c0000000000000 },
		{ 0x000000000000e0e0, 0x0000000000e0e0e0, 0x00000000e0e0e000, 0x000000e0e0e00000, 0x0000e0e0e0000000, 0x00e0e0e000000000, 0xe0e0e00000000000, 0xe0e0000000000000 },
		{ 0x0000000000007070, 0x0000000000707070, 0x0000000070707000, 0x0000007070700000, 0x0000707070000000, 0x0070707000000000, 0x7070700000000000, 0x7070000000000000 },
		{ 0x0000000000003838, 0x0000000000383838, 0x0000000038383800, 0x0000003838380000, 0x0000383838000000, 0x0038383800000000, 0x3838380000000000, 0x3838000000000000 },
		{ 0x0000000000001c1c, 0x00000000001c1c1c, 0x000000001c1c1c00, 0x0000001c1c1c0000, 0x00001c1c1c000000, 0x001c1c1c00000000, 0x1c1c1c0000000000, 0x1c1c000000000000 },
		{ 0x0000000000000e0e, 0x00000000000e0e0e, 0x000000000e0e0e00, 0x0000000e0e0e0000, 0x00000e0e0e000000, 0x000e0e0e00000000, 0x0e0e0e0000000000, 0x0e0e000000000000 },
		{ 0x0000000000000707, 0x0000000000070707, 0x0000000007070700, 0x0000000707070000, 0x0000070707000000, 0x0007070700000000, 0x0707070000000000, 0x0707000000000000 },
		{ 0x0000000000000303, 0x0000000000030303, 0x0000000003030300, 0x0000000303030000, 0x0000030303000000, 0x0003030300000000, 0x0303030000000000, 0x0303000000000000 }
	}};

	MoveTable constexpr Queen {{
		{ 0x8182848890a0c0ff, 0x82848890a0c0ffc0, 0x848890a0c0ffc0a0, 0x8890a0c0ffc0a090, 0x90a0c0ffc0a09088, 0xa0c0ffc0a0908884, 0xc0ffc0a090888482, 0xffc0a09088848281 },
		{ 0x404142444850e0ff, 0x4142444850e0ffe0, 0x42444850e0ffe050, 0x444850e0ffe05048, 0x4850e0ffe0504844, 0x50e0ffe050484442, 0xe0ffe05048444241, 0xffe0504844424140 },
		{ 0x2020212224a870ff, 0x20212224a870ff70, 0x212224a870ff70a8, 0x2224a870ff70a824, 0x24a870ff70a82422, 0xa870ff70a8242221, 0x70ff70a824222120, 0xff70a82422212020 },
		{ 0x10101011925438ff, 0x101011925438ff38, 0x1011925438ff3854, 0x11925438ff385492, 0x925438ff38549211, 0x5438ff3854921110, 0x38ff385492111010, 0xff38549211101010 },
		{ 0x08080888492a1cff, 0x080888492a1cff1c, 0x0888492a1cff1c2a, 0x88492a1cff1c2a49, 0x492a1cff1c2a4988, 0x2a1cff1c2a498808, 0x1cff1c2a49880808, 0xff1c2a4988080808 },
		{ 0x0404844424150eff, 0x04844424150eff0e, 0x844424150eff0e15, 0x4424150eff0e1524, 0x24150eff0e152444, 0x150eff0e15244484, 0x0eff0e1524448404, 0xff0e152444840404 },
		{ 0x02824222120a07ff, 0x824222120a07ff07, 0x4222120a07ff070a, 0x22120a07ff070a12, 0x120a07ff070a1222, 0x0a07ff070a122242, 0x07ff070a12224282, 0xff070a1222428202 },
		{ 0x81412111090503ff, 0x412111090503ff03, 0x2111090503ff0305, 0x11090503ff030509, 0x090503ff03050911, 0x0503ff0305091121, 0x03ff030509112141, 0xff03050911214181 }
	}};

	MoveTable constexpr Rook {{
		{ 0x80808080808080ff, 0x808080808080ff80, 0x8080808080ff8080, 0x80808080ff808080, 0x808080ff80808080, 0x8080ff8080808080, 0x80ff808080808080, 0xff80808080808080 },
		{ 0x40404040404040ff, 0x404040404040ff40, 0x4040404040ff4040, 0x40404040ff404040, 0x404040ff40404040, 0x4040ff4040404040, 0x40ff404040404040, 0xff40404040404040 },
		{ 0x20202020202020ff, 0x202020202020ff20, 0x2020202020ff2020, 0x20202020ff202020, 0x202020ff20202020, 0x2020ff2020202020, 0x20ff202020202020, 0xff20202020202020 },
		{ 0x10101010101010ff, 0x101010101010ff10, 0x1010101010ff1010, 0x10101010ff101010, 0x101010ff10101010, 0x1010ff1010101010, 0x10ff101010101010, 0xff10101010101010 },
		{ 0x08080808080808ff, 0x080808080808ff08, 0x0808080808ff0808, 0x08080808ff080808, 0x080808ff08080808, 0x0808ff0808080808, 0x08ff080808080808, 0xff08080808080808 },
		{ 0x04040404040404ff, 0x040404040404ff04, 0x0404040404ff0404, 0x04040404ff040404, 0x040404ff04040404, 0x0404ff0404040404, 0x04ff040404040404, 0xff04040404040404 },
		{ 0x02020202020202ff, 0x020202020202ff02, 0x0202020202ff0202, 0x02020202ff020202, 0x020202ff02020202, 0x0202ff0202020202, 0x02ff020202020202, 0xff02020202020202 },
		{ 0x01010101010101ff, 0x010101010101ff01, 0x0101010101ff0101, 0x01010101ff010101, 0x010101ff01010101, 0x0101ff0101010101, 0x01ff010101010101, 0xff01010101010101 }
	}};

	MoveTable constexpr Bishop {{
		{ 0x0102040810204080, 0x0204081020408040, 0x0408102040804020, 0x0810204080402010, 0x1020408040201008, 0x2040804020100804, 0x4080402010080402, 0x8040201008040201 },
		{ 0x000102040810a040, 0x0102040810a040a0, 0x02040810a040a010, 0x040810a040a01008, 0x0810a040a0100804, 0x10a040a010080402, 0xa040a01008040201, 0x40a0100804020100 },
		{ 0x0000010204885020, 0x0001020488502050, 0x0102048850205088, 0x0204885020508804, 0x0488502050880402, 0x8850205088040201, 0x5020508804020100, 0x2050880402010000 },
		{ 0x0000000182442810, 0x0000018244281028, 0x0001824428102844, 0x0182442810284482, 0x8244281028448201, 0x4428102844820100, 0x2810284482010000, 0x1028448201000000 },
		{ 0x0000008041221408, 0x0000804122140814, 0x0080412214081422, 0x8041221408142241, 0x4122140814224180, 0x2214081422418000, 0x1408142241800000, 0x0814224180000000 },
		{ 0x0000804020110a04, 0x00804020110a040a, 0x804020110a040a11, 0x4020110a040a1120, 0x20110a040a112040, 0x110a040a11204080, 0x0a040a1120408000, 0x040a112040800000 },
		{ 0x0080402010080502, 0x8040201008050205, 0x4020100805020508, 0x2010080502050810, 0x1008050205081020, 0x0805020508102040, 0x0502050810204080, 0x0205081020408000 },
		{ 0x8040201008040201, 0x4020100804020102, 0x2010080402010204, 0x1008040201020408, 0x0804020102040810, 0x0402010204081020, 0x0201020408102040, 0x0102040810204080 }
	}};

	MoveTable constexpr Knight {{
		{ 0x0000000000402080, 0x0000000040208020, 0x0000004020802040, 0x0000402080204000, 0x0040208020400000, 0x4020802040000000, 0x2080204000000000, 0x8020400000000000 },
		{ 0x0000000000a01040, 0x00000000a0104010, 0x000000a0104010a0, 0x0000a0104010a000, 0x00a0104010a00000, 0xa0104010a0000000, 0x104010a000000000, 0x4010a00000000000 },
		{ 0x0000000000508820, 0x0000000050882088, 0x0000005088208850, 0x0000508820885000, 0x0050882088500000, 0x5088208850000000, 0x8820885000000000, 0x2088500000000000 },
		{ 0x0000000000284410, 0x0000000028441044, 0x0000002844104428, 0x0000284410442800, 0x0028441044280000, 0x2844104428000000, 0x4410442800000000, 0x1044280000000000 },
		{ 0x0000000000142208, 0x0000000014220822, 0x0000001422082214, 0x0000142208221400, 0x0014220822140000, 0x1422082214000000, 0x2208221400000000, 0x0822140000000000 },
		{ 0x00000000000a1104, 0x000000000a110411, 0x0000000a1104110a, 0x00000a1104110a00, 0x000a1104110a0000, 0x0a1104110a000000, 0x1104110a00000000, 0x04110a0000000000 },
		{ 0x0000000000050802, 0x0000000005080208, 0x0000000508020805, 0x0000050802080500, 0x0005080208050000, 0x0508020805000000, 0x0802080500000000, 0x0208050000000000 },
		{ 0x0000000000020401, 0x0000000002040104, 0x0000000204010402, 0x0000020401040200, 0x0002040104020000, 0x0204010402000000, 0x0401040200000000, 0x0104020000000000 }
	}};



	//------------------------------- Special tables
	MoveTable constexpr upStraight {{
		{ 0x8080808080808080, 0x8080808080808000, 0x8080808080800000, 0x8080808080000000, 0x8080808000000000, 0x8080800000000000, 0x8080000000000000, 0x8000000000000000 },
		{ 0x4040404040404040, 0x4040404040404000, 0x4040404040400000, 0x4040404040000000, 0x4040404000000000, 0x4040400000000000, 0x4040000000000000, 0x4000000000000000 },
		{ 0x2020202020202020, 0x2020202020202000, 0x2020202020200000, 0x2020202020000000, 0x2020202000000000, 0x2020200000000000, 0x2020000000000000, 0x2000000000000000 },
		{ 0x1010101010101010, 0x1010101010101000, 0x1010101010100000, 0x1010101010000000, 0x1010101000000000, 0x1010100000000000, 0x1010000000000000, 0x1000000000000000 },
		{ 0x0808080808080808, 0x0808080808080800, 0x0808080808080000, 0x0808080808000000, 0x0808080800000000, 0x0808080000000000, 0x0808000000000000, 0x0800000000000000 },
		{ 0x0404040404040404, 0x0404040404040400, 0x0404040404040000, 0x0404040404000000, 0x0404040400000000, 0x0404040000000000, 0x0404000000000000, 0x0400000000000000 },
		{ 0x0202020202020202, 0x0202020202020200, 0x0202020202020000, 0x0202020202000000, 0x0202020200000000, 0x0202020000000000, 0x0202000000000000, 0x0200000000000000 },
		{ 0x0101010101010101, 0x0101010101010100, 0x0101010101010000, 0x0101010101000000, 0x0101010100000000, 0x0101010000000000, 0x0101000000000000, 0x0100000000000000 }
	}};

	MoveTable constexpr downStraight {{
		{ 0x0000000000000080, 0x0000000000008080, 0x0000000000808080, 0x0000000080808080, 0x0000008080808080, 0x0000808080808080, 0x0080808080808080, 0x8080808080808080 },
		{ 0x0000000000000040, 0x0000000000004040, 0x0000000000404040, 0x0000000040404040, 0x0000004040404040, 0x0000404040404040, 0x0040404040404040, 0x4040404040404040 },
		{ 0x0000000000000020, 0x0000000000002020, 0x0000000000202020, 0x0000000020202020, 0x0000002020202020, 0x0000202020202020, 0x0020202020202020, 0x2020202020202020 },
		{ 0x0000000000000010, 0x0000000000001010, 0x0000000000101010, 0x0000000010101010, 0x0000001010101010, 0x0000101010101010, 0x0010101010101010, 0x1010101010101010 },
		{ 0x0000000000000008, 0x0000000000000808, 0x0000000000080808, 0x0000000008080808, 0x0000000808080808, 0x0000080808080808, 0x0008080808080808, 0x0808080808080808 },
		{ 0x0000000000000004, 0x0000000000000404, 0x0000000000040404, 0x0000000004040404, 0x0000000404040404, 0x0000040404040404, 0x0004040404040404, 0x0404040404040404 },
		{ 0x0000000000000002, 0x0000000000000202, 0x0000000000020202, 0x0000000002020202, 0x0000000202020202, 0x0000020202020202, 0x0002020202020202, 0x0202020202020202 },
		{ 0x0000000000000001, 0x0000000000000101, 0x0000000000010101, 0x0000000001010101, 0x0000000101010101, 0x0000010101010101, 0x0001010101010101, 0x0101010101010101 }
	}};

	MoveTable constexpr rightStraight {{
		{ 0x00000000000000ff, 0x000000000000ff00, 0x0000000000ff0000, 0x00000000ff000000, 0x000000ff00000000, 0x0000ff0000000000, 0x00ff000000000000, 0xff00000000000000 },
		{ 0x000000000000007f, 0x0000000000007f00, 0x00000000007f0000, 0x000000007f000000, 0x0000007f00000000, 0x00007f0000000000, 0x007f000000000000, 0x7f00000000000000 },
		{ 0x000000000000003f, 0x0000000000003f00, 0x00000000003f0000, 0x000000003f000000, 0x0000003f00000000, 0x00003f0000000000, 0x003f000000000000, 0x3f00000000000000 },
		{ 0x000000000000001f, 0x0000000000001f00, 0x00000000001f0000, 0x000000001f000000, 0x0000001f00000000, 0x00001f0000000000, 0x001f000000000000, 0x1f00000000000000 },
		{ 0x000000000000000f, 0x0000000000000f00, 0x00000000000f0000, 0x000000000f000000, 0x0000000f00000000, 0x00000f0000000000, 0x000f000000000000, 0x0f00000000000000 },
		{ 0x0000000000000007, 0x0000000000000700, 0x0000000000070000, 0x0000000007000000, 0x0000000700000000, 0x0000070000000000, 0x0007000000000000, 0x0700000000000000 },
		{ 0x0000000000000003, 0x0000000000000300, 0x0000000000030000, 0x0000000003000000, 0x0000000300000000, 0x0000030000000000, 0x0003000000000000, 0x0300000000000000 },
		{ 0x0000000000000001, 0x0000000000000100, 0x0000000000010000, 0x0000000001000000, 0x0000000100000000, 0x0000010000000000, 0x0001000000000000, 0x0100000000000000 }
	}};

	MoveTable constexpr leftStraight {{
		{ 0x0000000000000080, 0x0000000000008000, 0x0000000000800000, 0x0000000080000000, 0x0000008000000000, 0x0000800000000000, 0x0080000000000000, 0x8000000000000000 },
		{ 0x00000000000000c0, 0x000000000000c000, 0x0000000000c00000, 0x00000000c0000000, 0x000000c000000000, 0x0000c00000000000, 0x00c0000000000000, 0xc000000000000000 },
		{ 0x00000000000000e0, 0x000000000000e000, 0x0000000000e00000, 0x00000000e0000000, 0x000000e000000000, 0x0000e00000000000, 0x00e0000000000000, 0xe000000000000000 },
		{ 0x00000000000000f0, 0x000000000000f000, 0x0000000000f00000, 0x00000000f0000000, 0x000000f000000000, 0x0000f00000000000, 0x00f0000000000000, 0xf000000000000000 },
		{ 0x00000000000000f8, 0x000000000000f800, 0x0000000000f80000, 0x00000000f8000000, 0x000000f800000000, 0x0000f80000000000, 0x00f8000000000000, 0xf800000000000000 },
		{ 0x00000000000000fc, 0x000000000000fc00, 0x0000000000fc0000, 0x00000000fc000000, 0x000000fc00000000, 0x0000fc0000000000, 0x00fc000000000000, 0xfc00000000000000 },
		{ 0x00000000000000fe, 0x000000000000fe00, 0x0000000000fe0000, 0x00000000fe000000, 0x000000fe00000000, 0x0000fe0000000000, 0x00fe000000000000, 0xfe00000000000000 },
		{ 0x00000000000000ff, 0x000000000000ff00, 0x0000000000ff0000, 0x00000000ff000000, 0x000000ff00000000, 0x0000ff0000000000, 0x00ff000000000000, 0xff00000000000000 }
	}};

	MoveTable constexpr upRight {{
		{ 0x0102040810204080, 0x0204081020408000, 0x0408102040800000, 0x0810204080000000, 0x1020408000000000, 0x2040800000000000, 0x4080000000000000, 0x8000000000000000 },
		{ 0x0001020408102040, 0x0102040810204000, 0x0204081020400000, 0x0408102040000000, 0x0810204000000000, 0x1020400000000000, 0x2040000000000000, 0x4000000000000000 },
		{ 0x0000010204081020, 0x0001020408102000, 0x0102040810200000, 0x0204081020000000, 0x0408102000000000, 0x0810200000000000, 0x1020000000000000, 0x2000000000000000 },
		{ 0x0000000102040810, 0x0000010204081000, 0x0001020408100000, 0x0102040810000000, 0x0204081000000000, 0x0408100000000000, 0x0810000000000000, 0x1000000000000000 },
		{ 0x0000000001020408, 0x0000000102040800, 0x0000010204080000, 0x0001020408000000, 0x0102040800000000, 0x0204080000000000, 0x0408000000000000, 0x0800000000000000 },
		{ 0x0000000000010204, 0x0000000001020400, 0x0000000102040000, 0x0000010204000000, 0x0001020400000000, 0x0102040000000000, 0x0204000000000000, 0x0400000000000000 },
		{ 0x0000000000000102, 0x0000000000010200, 0x0000000001020000, 0x0000000102000000, 0x0000010200000000, 0x0001020000000000, 0x0102000000000000, 0x0200000000000000 },
		{ 0x0000000000000001, 0x0000000000000100, 0x0000000000010000, 0x0000000001000000, 0x0000000100000000, 0x0000010000000000, 0x0001000000000000, 0x0100000000000000 }
	}};

	MoveTable constexpr upLeft {{
		{ 0x0000000000000080, 0x0000000000008000, 0x0000000000800000, 0x0000000080000000, 0x0000008000000000, 0x0000800000000000, 0x0080000000000000, 0x8000000000000000 },
		{ 0x0000000000008040, 0x0000000000804000, 0x0000000080400000, 0x0000008040000000, 0x0000804000000000, 0x0080400000000000, 0x8040000000000000, 0x4000000000000000 },
		{ 0x0000000000804020, 0x0000000080402000, 0x0000008040200000, 0x0000804020000000, 0x0080402000000000, 0x8040200000000000, 0x4020000000000000, 0x2000000000000000 },
		{ 0x0000000080402010, 0x0000008040201000, 0x0000804020100000, 0x0080402010000000, 0x8040201000000000, 0x4020100000000000, 0x2010000000000000, 0x1000000000000000 },
		{ 0x0000008040201008, 0x0000804020100800, 0x0080402010080000, 0x8040201008000000, 0x4020100800000000, 0x2010080000000000, 0x1008000000000000, 0x0800000000000000 },
		{ 0x0000804020100804, 0x0080402010080400, 0x8040201008040000, 0x4020100804000000, 0x2010080400000000, 0x1008040000000000, 0x0804000000000000, 0x0400000000000000 },
		{ 0x0080402010080402, 0x8040201008040200, 0x4020100804020000, 0x2010080402000000, 0x1008040200000000, 0x0804020000000000, 0x0402000000000000, 0x0200000000000000 },
		{ 0x8040201008040201, 0x4020100804020100, 0x2010080402010000, 0x1008040201000000, 0x0804020100000000, 0x0402010000000000, 0x0201000000000000, 0x0100000000000000 }
	}};

	MoveTable constexpr downRight {{
		{ 0x0000000000000080, 0x0000000000008040, 0x0000000000804020, 0x0000000080402010, 0x0000008040201008, 0x0000804020100804, 0x0080402010080402, 0x8040201008040201 },
		{ 0x0000000000000040, 0x0000000000004020, 0x0000000000402010, 0x0000000040201008, 0x0000004020100804, 0x0000402010080402, 0x0040201008040201, 0x4020100804020100 },
		{ 0x0000000000000020, 0x0000000000002010, 0x0000000000201008, 0x0000000020100804, 0x0000002010080402, 0x0000201008040201, 0x0020100804020100, 0x2010080402010000 },
		{ 0x0000000000000010, 0x0000000000001008, 0x0000000000100804, 0x0000000010080402, 0x0000001008040201, 0x0000100804020100, 0x0010080402010000, 0x1008040201000000 },
		{ 0x0000000000000008, 0x0000000000000804, 0x0000000000080402, 0x0000000008040201, 0x0000000804020100, 0x0000080402010000, 0x0008040201000000, 0x0804020100000000 },
		{ 0x0000000000000004, 0x0000000000000402, 0x0000000000040201, 0x0000000004020100, 0x0000000402010000, 0x0000040201000000, 0x0004020100000000, 0x0402010000000000 },
		{ 0x0000000000000002, 0x0000000000000201, 0x0000000000020100, 0x0000000002010000, 0x0000000201000000, 0x0000020100000000, 0x0002010000000000, 0x0201000000000000 },
		{ 0x0000000000000001, 0x0000000000000100, 0x0000000000010000, 0x0000000001000000, 0x0000000100000000, 0x0000010000000000, 0x0001000000000000, 0x0100000000000000 }
	}};

	MoveTable constexpr downLeft {{
		{ 0x0000000000000080, 0x0000000000008000, 0x0000000000800000, 0x0000000080000000, 0x0000008000000000, 0x0000800000000000, 0x0080000000000000, 0x8000000000000000 },
		{ 0x0000000000000040, 0x0000000000004080, 0x0000000000408000, 0x0000000040800000, 0x0000004080000000, 0x0000408000000000, 0x0040800000000000, 0x4080000000000000 },
		{ 0x0000000000000020, 0x0000000000002040, 0x0000000000204080, 0x0000000020408000, 0x0000002040800000, 0x0000204080000000, 0x0020408000000000, 0x2040800000000000 },
		{ 0x0000000000000010, 0x0000000000001020, 0x0000000000102040, 0x0000000010204080, 0x0000001020408000, 0x0000102040800000, 0x0010204080000000, 0x1020408000000000 },
		{ 0x0000000000000008, 0x0000000000000810, 0x0000000000081020, 0x0000000008102040, 0x0000000810204080, 0x0000081020408000, 0x0008102040800000, 0x0810204080000000 },
		{ 0x0000000000000004, 0x0000000000000408, 0x0000000000040810, 0x0000000004081020, 0x0000000408102040, 0x0000040810204080, 0x0004081020408000, 0x0408102040800000 },
		{ 0x0000000000000002, 0x0000000000000204, 0x0000000000020408, 0x0000000002040810, 0x0000000204081020, 0x0000020408102040, 0x0002040810204080, 0x0204081020408000 },
		{ 0x0000000000000001, 0x0000000000000102, 0x0000000000010204, 0x0000000001020408, 0x0000000102040810, 0x0000010204081020, 0x0001020408102040, 0x0102040810204080 }
	}};

	//Do we make a move table for pawns? Maybe lol.
}