require 'mxx_ru/cpp'
MxxRu::Cpp::exe_target {

	required_prj( "so_5/prj.rb" )

	target( "_unit.test.coop.introduce_coop_4" )

	cpp_source( "main.cpp" )
}

