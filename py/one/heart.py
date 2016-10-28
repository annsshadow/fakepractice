print'\n'.join([''.join([('IcyCreamYeah'[(x-y)%12]if((x*0.05)**2+(y*0.1)**2-1)**3-(x*0.05)**2*(y*0.1)**3<=0 else' ')for x in range(-40,40)])for y in range(20,-20,-1)])
