extern crate inline_colorization;

use std::fs;
use std::io;
use std::env;
use std::path::Path;
use std::fs::File;
use inline_colorization::*;
use std::process;

pub fn list_files(dir: &str) {
    let paths = fs::read_dir(dir).unwrap();

    for path in paths {
        print!("\n{}", path.unwrap().path().display());
    }
}

pub fn scanf() -> String {
    let mut input = String::new();

    io::stdin().read_line(&mut input).expect("{color_red}[ERROR]: Couldn't scan input.{color_reset}");

    return input;
}

pub fn main() {

    loop {
        /* Display the menu */
        print!("\n{color_blue}===================================");
        print!("\n{color_blue}|       {color_yellow}THE ZE FILE EXPLORER{color_blue}      |");
        print!("\n{color_blue}===================================");
        print!("\n{color_blue}| {color_green}1. View files{color_blue}                   |");
        print!("\n{color_blue}| {color_green}2. Change directory{color_blue}             |");
        print!("\n{color_blue}| {color_green}3. Create file{color_blue}                  |");
        print!("\n{color_blue}| {color_green}4. Delete file{color_blue}                  |");
        print!("\n{color_blue}| {color_red}5. Exit{color_blue}                         |");
        print!("\n{color_blue}===================================");
        print!("\n{color_magenta}%{color_blue} ");

        match scanf().trim() {
            "1" => {
                /* List files and directories in the given path */
                print!("\n{color_magenta}>{color_blue} ");
                list_files(&scanf());
            }

            "2" => {
                /* Change the current working directory */
                print!("\n{color_magenta}>{color_blue} ");
                let input = scanf();
                let path = Path::new(&input);
                assert!(env::set_current_dir(&path).is_ok());
                print!("\n{color_green}[INFO]: Successfully changed directory to {}", path.display())
            }

            "3" => {
                /* Create a new file */
                print!("\n{color_magenta}>{color_blue} ");
                let filename = scanf();
                assert!(File::create(&filename).is_ok());
                print!("\n{color_green}[INFO]: Successfully created file {}{color_blue}", filename);
            }

            "4" => {
                /* Delete an existing file */
                print!("\n{color_magenta}>{color_blue} ");
                let filename = scanf();
                assert!(fs::remove_file(&filename).is_ok());
                print!("\n{color_green}[INFO]: Successfully removed {}{color_blue}", filename);
            }

            "5" => {
                /* Exit the program */
                print!("\n{color_green}[INFO]: Exiting...{color_reset}\n");
                process::exit(0x0100);
            }

            _ => {
                print!("\n{color_red}[ERROR]: Invalid expression{color_blue}");
            }
        }
    }
}
