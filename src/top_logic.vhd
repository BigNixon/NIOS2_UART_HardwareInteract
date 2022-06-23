library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity top_logic is

	port(
		clk:	in std_logic;
		rst:	in std_logic;
		sel:	in std_logic_vector(1 downto 0);
		
		
		led:	out std_logic
	);

end top_logic;

architecture arch_by_sel of top_logic is 
    signal scount: integer range 0 to 50000000;
    signal freq:    integer range 0 to 50000000;
    signal freq_2: integer range 0 to 50000000; 
begin
    
    freq <= 50000000 when sel="00" else
            25000000 when sel="01" else
            12000000 when sel="10" else
             2000000;
    freq_2 <= freq/2;
    
   process(clk,rst)
    begin
        if (rst='0') then
            led <= '0';
            scount <= 0;
        elsif (rising_edge(clk))then
            if(scount<freq)then
                scount <= scount+1;
                if(scount < freq_2)then
                    led <= '0';
                else 
                    led <= '1';
                end if;
            else
                scount <= 0;
            end if;
        end if;
    end process;



end architecture;