library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity memory is
	port
	(
		clk			: in  std_logic;
		rst			: in  std_logic;
		memread			: in  std_logic;
		memwrite		: in  std_logic;
		address1		: in  std_logic_vector (31 downto 0);
		address2		: in  std_logic_vector (31 downto 0);
		writedata		: in  std_logic_vector (31 downto 0);
		instruction		: out std_logic_vector (31 downto 0);
		readdata		: out std_logic_vector (31 downto 0)
	);
end memory;

architecture behavior of memory is
	type ramcell is array (0 to 255) of std_logic_vector (7 downto 0);
	signal ram			: ramcell;
	signal masked1, masked2		: std_logic_vector (7 downto 0);
	signal selector1, selector2	: natural range 0 to 255;
begin
	masked1 <= address1 (7 downto 2) & "00";
	masked2 <= address2 (7 downto 2) & "00";
	selector1 <= to_integer (unsigned (masked1));
	selector2 <= to_integer (unsigned (masked2));

	process (clk, rst, memread, memwrite, address1, address2, writedata)
	begin
		if (rising_edge (clk)) then
			if (rst = '1') then
				ram (  0) <= "00010100"; -- addi $s1,$0,20
				ram (  1) <= "00000000";
				ram (  2) <= "00010001";
				ram (  3) <= "00100000";
				ram (  4) <= "00000010"; -- addi $s2,$0,2
				ram (  5) <= "00000000";
				ram (  6) <= "00010010";
				ram (  7) <= "00100000";
				ram (  8) <= "00000000"; -- addi $s3,$0,0
				ram (  9) <= "00000000";
				ram ( 10) <= "00010011";
				ram ( 11) <= "00100000";
				ram ( 12) <= "00000100"; -- sllv $s3,$s1,$s2
				ram ( 13) <= "10011000";
				ram ( 14) <= "01010001";
				ram ( 15) <= "00000010";
				for i in 16 to 255 loop
					ram (i) <= std_logic_vector (to_unsigned (0, 8));
				end loop;
			else
				if (memwrite = '1') then
					ram (selector2 + 0) <= writedata (7 downto 0);
					ram (selector2 + 1) <= writedata (15 downto 8);
					ram (selector2 + 2) <= writedata (23 downto 16);
					ram (selector2 + 3) <= writedata (31 downto 24);
				end if;
			end if;
		end if;
	end process;
	instruction <= ram (selector1 + 3) & ram (selector1 + 2) & ram (selector1 + 1) & ram (selector1 + 0);
	with memread select
		readdata <=	std_logic_vector (to_unsigned (0, 32)) when '0',
				ram (selector2 + 3) & ram (selector2 + 2) & ram (selector2 + 1) & ram (selector2 + 0) when others;
end behavior;
