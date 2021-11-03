**Note: This is under development and is not in any playable state yet**

# ROTTEN

![screeshot.png](https://cdn.discordapp.com/attachments/814530214838927371/902690543723769896/unknown.png)

Rotten is a simple text adventure game with vim
like input keys.

## Geting Started:
### Build from Source:
```sh
git clone https://github.com/Erarnitox/RottenTextAdventure
cd RottenTextAdventure/src
make
```
#### Run the Game:
You can after building the game run the Game from the `src` directory
using:
```sh
make run
```

Alternatively the compiled binary can be found in the `bin` directory.

### Navigation:
- `j` : select next option
- `k` : select previous option
- `l` : select next item
- `h` : select previous item
- `:` : open console for commands and custom options
- `t` : take selected item 
- `s` : choose the selected option
- `i` : list items in inventory

#### Commands:
- `q` : quit the game
- `drop [itemId] [count]` : drop an Item from inventory
- `use [itemId] [count]` : use an Item from inventory
