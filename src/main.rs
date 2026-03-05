unsafe extern "C" 
{ 
    fn very_safe_code();
}

fn main() 
{
    unsafe {
        very_safe_code();
    }
}
