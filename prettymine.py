# converts vector to list in python
def vector_to_list(std_vector):
    out_list = []
    value_reference = std_vector['_M_impl']['_M_start']
    while value_reference != std_vector['_M_impl']['_M_finish']:
        out_list.append(value_reference.dereference())
        value_reference += 1

    return out_list

class MineSweeperPrinter:
    def __init__(self, val):
        self.val = val;

    def to_string(self):
        rows = self.val['rows']
        cols = self.val['cols']
        game_state = self.val['current_state']
        grid = self.val['grid']
        mine_map = self.val['mine_map']
        str_val = "MineSweeper Object { \n"
        str_val += "rows: " + str(rows) + '\n'
        str_val += "cols: " + str(cols) + '\n'
        str_val += "current_state: " + str(game_state) + '\n'
        #str_val += "grid: " + str(grid) + '\n'
        str_val += "mine_map: " + str(mine_map) + '\n'
        str_val += "}\n"

        return str_val

class MineMapPrinter:
    def __init__(self, val):
        self.val = val

    def to_string(self):
        cells = self.val['cells']
        cells_list = vector_to_list(cells)

        x = self.val['x']
        y = self.val['y']

        string_map = "\n"

        for row in range(0,int(x)):
            # Current row of vector
            #string_map += str(cells_list[row])

            # Convert vector row to list
            cell_row = vector_to_list(cells_list[row])
            # Go through list of elements in row
            for column in range(0,int(y)):
                string_map += str(cell_row[column]) + " "

            # Have string go to next row
            string_map += '\n'

        return string_map

class CellPrinter:
    def __init__(self,val):
        self.val = val

    def to_string(self):
        x = self.val['x']
        y = self.val['y']

        cell_state = self.val['cell_state']
        current_state = cell_state['state']
        string_cell = ""
        # Match value of cell
        if current_state == 0:
            string_cell = "C"
        elif current_state == 1:
            value = self.val['value']
            string_cell = str(value)
        elif current_state == 2:
            string_cell = "F"
        elif current_state == 3:
            string_cell = "B"
        elif current_state == 4:
            string_cell = "Q"
        return string_cell

# called to print string of object type
def my_pp_func(val):
    if str(val.type) == 'MineSweeper':
        return MineSweeperPrinter(val)
    elif str(val.type) == 'MineMap':
        return MineMapPrinter(val)
    elif str(val.type) == 'Cell':
        return CellPrinter(val)

gdb.pretty_printers.append(my_pp_func)
