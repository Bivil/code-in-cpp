def call_block
    puts "Start of method."
    yield
    puts "End of method."
end 
call_block do 
    puts "I am inside call_block method."
end

