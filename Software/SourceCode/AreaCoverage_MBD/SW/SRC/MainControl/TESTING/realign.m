function realign(varargin)
% REALIGN adjusts the position of IO port of a subsystem selected
%
%   This script is a version of REALIGN tool that applies only on
%   SubSystems.

%   Author: K. ELKHESSAIRI
%   Copyright 2009 Valeo
%   $Revision:   1.2  $  $Date:   10 Nov 2015 10:16:42  $
if(nargin==0)
    varargin=gcb;
end

kLst_Blks = find_system(varargin, 'Type', 'block');
kCur_Blk = kLst_Blks(1);
kCur_Blk_Type = get_param(kCur_Blk, 'BlockType');
ni = 0;
nj = 0;
if(strcmp(kCur_Blk_Type,'SubSystem'))
  kLst_Nbr_Ports = get_param(kCur_Blk, 'Ports');
  kLst_Nbr_Inports = kLst_Nbr_Ports{1,1}(1);
  kLst_Nbr_Outports = kLst_Nbr_Ports{1,1}(2);
  kLst_Nbr_Enables = kLst_Nbr_Ports{1,1}(3);
  kLst_Nbr_Triggers = kLst_Nbr_Ports{1,1}(4);
  kLst_Nbr_Ins = kLst_Nbr_Inports + kLst_Nbr_Triggers + kLst_Nbr_Enables;
  kLst_Cur_IOPorts_Connect = get_param(kCur_Blk, 'PortConnectivity');
  if(kLst_Nbr_Inports ~= 0)
      for i=1:kLst_Nbr_Inports
          kHndl_Inport = kLst_Cur_IOPorts_Connect{1,1}(i,1).SrcBlock(1);
          if(kHndl_Inport ~= -1)
              kInport_Blk_Type = get_param(kHndl_Inport, 'BlockType');
              if((strcmp(kInport_Blk_Type,'From') ~= 0) || (strcmp(kInport_Blk_Type,'Inport') ~= 0))
                  if(ni == 0)
                      ni = i;
                  end;
                  f_Alignement_Blocks(kCur_Blk,i,0,ni);
              end;
          end;
      end;
  end;
  for j=1:kLst_Nbr_Outports
     if(kLst_Cur_IOPorts_Connect{1,1}(j+kLst_Nbr_Ins,1).DstBlock)
         for k=1:length(kLst_Cur_IOPorts_Connect{1,1}(j+kLst_Nbr_Ins,1).DstBlock)
             if(nj == 0)
                 nj = j;
             end;
             if(kLst_Nbr_Inports==0)
                 f_Alignement_Blocks(kCur_Blk,j,-1,nj);
             else
                 f_Alignement_Blocks(kCur_Blk,j+kLst_Nbr_Ins,kLst_Nbr_Ins,nj);
             end;
         end;
     end;
  end;
else
    Display('The selected block is not a SubSystem!','warning','True');
end;


function f_Alignement_Blocks(SubSystem, Index_Lst, Index_Offset, Index_Ref_X)
% F_ALIGNEMENT_BLOCKS adjusts the position of IO port to those of In/Out 
%   reference port.
%
%   This function is a helper for REALIGN tool and other
%   Simulink context functionality.
%
%   F_ALIGNEMENT_BLOCKS(SUBSYSTEM, INDEX_LST, INDEX_OFFSET) adjusts the
%   position of IO port block having the INDEX_LST index in the list of
%   port connections to those of In/Out reference port of the corresponding
%   subsystem given by the SUBSYSTEM handle. The direction of the port is
%   given by the INDEX_OFFSET (the parameter indicates the number of inputs
%   in the case of outputs and 0 in the case of inputs).

Lst_Cur_IOPorts_Connect = get_param(SubSystem, 'PortConnectivity');
if(Index_Offset == 0) % Inputs Handling
    VY = Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).Position(2);
    VX = get_param(Lst_Cur_IOPorts_Connect{1,1}(Index_Ref_X,1).SrcBlock(1), 'Position');
    Vold = get_param(Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).SrcBlock(1), 'Position');
    if(Index_Lst == 1)
        kx1 = Vold(1);
        kx2 = Vold(3);
    else
        kx1 = VX(3) + Vold(1) - Vold(3);
        kx2 = VX(3);
    end;
    ky1 = VY - 0.5 * (Vold(4) - Vold(2));
    ky2 = VY + 0.5 * (Vold(4) - Vold(2));
    try
        set_param(Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).SrcBlock(1), 'Position', [kx1,ky1,kx2,ky2]);
    catch
        Lib_Path = getfullname(gcb);
        vect_lib_name = regexp(Lib_Path,'/','split');
        Lib_Name = char(vect_lib_name(1));
        set_param(Lib_Name,'lock', 'off');
        set_param(Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).SrcBlock(1), 'Position', [kx1,ky1,kx2,ky2]);
    end;
else  % Outputs Handling
    for k=1:length(Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).DstBlock) % Multi-branch handling
        if(Index_Offset == -1)
            Index_Offset = 0;
        end;
        VX = get_param(Lst_Cur_IOPorts_Connect{1,1}(Index_Offset+Index_Ref_X,1).DstBlock(1), 'Position');
        VY = Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).Position(2);
        Vold = get_param(Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).DstBlock(k), 'Position');
        if(Index_Lst == 1)
            kx1 = Vold(1);
            kx2 = Vold(3);
        else
            kx1 = VX(1);
            kx2 = VX(1) + Vold(3) - Vold(1);
        end;
        if(k == 1)
            ky1 = VY - 0.5 * (Vold(4) - Vold(2));
            ky2 = VY + 0.5 * (Vold(4) - Vold(2));
        else
            ky1 = Vold(2);
            ky2 = Vold(4);
        end;
        local_block_type = get_param(Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).DstBlock(k),'blocktype');
        if((strcmp(local_block_type,'Goto') ~= 0) || (strcmp(local_block_type,'Outport') ~= 0))
            try
                set_param(Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).DstBlock(k), 'Position', [kx1,ky1,kx2,ky2]);
            catch
                Lib_Path = getfullname(gcb);
                vect_lib_name = regexp(Lib_Path,'/','split');
                Lib_Name = char(vect_lib_name(1));
                set_param(Lib_Name,'lock', 'off');
                set_param(Lst_Cur_IOPorts_Connect{1,1}(Index_Lst,1).DstBlock(k), 'Position', [kx1,ky1,kx2,ky2]);
            end;
        end;
    end;
end;

% Display
function Display(Arg_Msg,Arg_Type,Arg_Mode)
if(strcmpi(Arg_Mode,'True'))
    if(strcmpi(Arg_Type,'warning'))
        h = msgbox(Arg_Msg,Arg_Type,'warn');  % Gui Mode Warning
    elseif(strcmpi(Arg_Type,'error'))
        h = msgbox(Arg_Msg,Arg_Type,'error'); % Gui Mode Error
    else 
        h = msgbox(Arg_Msg,Arg_Type,'help');  % Gui Mode Info
    end
else
    disp([Arg_Type ': ' Arg_Msg ]);           % Terminal
end

%% EOF %%