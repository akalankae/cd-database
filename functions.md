## functions.md
## Functions needed for the CD database program.

✓ 1. read record name => `read_str(prompt)`  
✓ 2. named record exists => `record_exists(record_name)`  
✓ 3. read required number of CDs => `read_int(prompt)`  
✓ 4. read CD from keyboard => `read_cd(cd) [kbd->memory]`  
✓ 5. print CD to screen => `print_cd(cd) [memory->display]`
✓ 6. read CD from record => `read_cd_from_file(cd, file) [file->memory]`
✓ 7. write CD to a record => `write_cd_to_file(cd, file) [memory->file]`
 8. print names of available records => `print_records(dir_path)`
✓ 9. print CD titles in record => `print_cd_titles(record)`
✓10. delete record => `del_record(record_name)`
✓11. verify Nth CD exists => `read_num_option(prompt, #min, #max, err_msg)`
✓12. copy CD from one record to another => `copy_cd(cd, from_file, to_file)`
✓13. read Nth CD from record => `read_nth_cd_from_file(cd, file, cd_number)`
